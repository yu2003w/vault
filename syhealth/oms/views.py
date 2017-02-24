##################################################################################
# Written by Jared on April 9, 2016.
# All rights reserved.
#
##################################################################################
from django.shortcuts import render

# Create your views here.
from django.utils import timezone
from django.shortcuts import render,get_object_or_404
from django.http import HttpResponse, HttpResponseRedirect, Http404
from django.template import loader
from django.core.urlresolvers import reverse
from django.views import generic
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
from django.core.exceptions import ValidationError

from django.views.generic.edit import CreateView, UpdateView, DeleteView

# user log in required
from django.contrib.auth.decorators import login_required
from django.contrib.auth import views as auth_views
from django.contrib.auth.mixins import LoginRequiredMixin

# classes defined
from .utility import Good_Cost, ShoppingCart_Cost, OrderContent, ItemInCart

from .models import Product, ProductCR, CartItem, Order, RetailerInfo

# import stuff defined in forms.py
from django.forms import modelformset_factory
from .forms import BaseCartItemFormSet, CartItemForm

# Need to consider pagination problem here
class ProductList(generic.ListView):
    model = Product
    template_name = "product/product_list.html"
    context_object_name = 'product_list'

    """
    A little interesting here. Using class based views, if need to retrieve more information, the attribute should
    be set in context. Then in html template, the value could be used directly as context_object_name.
    """
    def get_context_data(self, **kwargs):
        context = super(ProductList, self).get_context_data(**kwargs)
        context['user'] = self.request.user
        return context
    
    def get_queryset(self):

        try:
            # For staff and super user, they should see all the objects.
            # For retailers, only products in sale could be found.
            if self.request.user.syuser.is_admin():
                proList = Product.objects.order_by('-status')
            elif self.request.user.syuser.is_retailer():
                proList = Product.objects.filter(status = True)
            else:
                raise Http404("You couldn't review product list here.")
        except Product.DoesNotExist:
            raise Http404("Product information doesn't exist")
        
        # show 15 records per page
        paginator = Paginator(proList, 15)
        page = self.request.GET.get('page') 
        try:
            prots = paginator.page(page)
        except PageNotAnInteger:
            # If page is not an integer, deliver first page.
            prots = paginator.page(1)
        except EmptyPage:
            # If page is out of range (e.g. 9999), deliver last page of results.
            prots = paginator.page(paginator.num_pages)

        return prots
            
class ProductDetail(generic.DetailView):
    model = Product
    template_name = "product/product_detail.html"
    context_object_name = "product_detail"

    def get_queryset(self):
        try:
            detail = Product.objects.filter(pk=self.kwargs['pk'])            
        except Product.DoesNotExist:
            raise Http404("Product doesn't exist")
        if not detail:
            raise Http404("Specified product doesn't exist")
        return detail

    def get_context_data(self, **kwargs):
        context = super(ProductDetail, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        return context

###########################################################################################
# Noted: New object is created and saved via form_valid(). To display the record,
#        redirect to success page. Need to overwrite get_absolute_url which is defined
#        in equivalent Model.
###########################################################################################
class ProductCreation(CreateView):
    model = Product
    fields = ['product_name', 'product_description', 'quantity', 'price', 'discount', 'status']
    template_name = "product/product_creation.html"
    
    def get_context_data(self, **kwargs):
        context = super(ProductCreation, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        return context

    """
    When Product is created, want to create related history record automatically.
    Need to overwrite form_valid()
    """
    def form_valid(self, form):
        obj = form.save(commit=False)
        response = super(ProductCreation, self).form_valid(form)
        # need to record history for product creation
        cr = ProductCR.objects.create(
            rec_pro = self.object,
            cr_reason = str(self.object) + " 创建成功.",
            user_admin = self.request.user.syuser
        )
        cr.save() 

        if obj.status == True :
           cr = ProductCR.objects.create(
               rec_pro = self.object,
               cr_reason = str(self.object) + " 成功上架.",
               user_admin = self.request.user.syuser
        )
        cr.save() 
        return response
        

    
#########################################################################################
# Once product is created, only quantity, price and discount could be updated.
# When product is updated, operation history should be recorded.
#########################################################################################
class ProductUpdate(UpdateView):
    model = Product 
    fields = ['quantity', 'price', 'discount', 'status']
    template_name = "product/product_update.html"

    """
    Return back to product list after successfully deleted selected object
    """
    def get_success_url(self):
        return reverse('oms:ProductList')

    def get_context_data(self, **kwargs):
        context = super(ProductUpdate, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        return context

    """
    When Product is created, want to create related history record automatically.
    Need to overwrite form_valid()
    """
    def form_valid(self, form):
        # old object is the original one before "post"
        old_object = Product.objects.get(pk=self.kwargs['pk'])
        pre_qa = old_object.quantity
        pre_price = old_object.price
        pre_discount = old_object.discount
        pre_status = old_object.status
         
        obj = form.save(commit=False)
        # a little tricky here, obj.quantity here is the increment number for product update.
        qa_added = obj.quantity
        obj.quantity += pre_qa

        cur_price = self.object.price
        cur_discount = self.object.discount
       
        response = super(ProductUpdate, self).form_valid(form)

        if (qa_added != 0):
            change_reason = str(self.object) + "库存变化" + str(qa_added) + "."
            cr = ProductCR.objects.create(
                rec_pro = self.object,
                cr_reason = change_reason,
                user_admin = self.request.user.syuser,
            )
            cr.save() 
        if (cur_price != pre_price):
            change_reason = str(self.object) + "调整前价格" + str(pre_price) + "."
            cr = ProductCR.objects.create(
                rec_pro = self.object,
                cr_reason = change_reason,
                user_admin = self.request.user.syuser
            )
            cr.save() 
        if (cur_discount != pre_discount):
            change_reason = str(self.object) + "调整前折扣" + str(pre_discount) + "."
            cr = ProductCR.objects.create(
                rec_pro = self.object,
                cr_reason = change_reason,
                user_admin = self.request.user.syuser
            )
            cr.save() 
        if (pre_status != obj.status):
            if pre_status == True:
                change_reason = str(self.object) + " 成功下架."
            else:
                change_reason = str(self.object) + " 成功上架."
            cr = ProductCR.objects.create(
                rec_pro = self.object,
                cr_reason = change_reason,
                user_admin = self.request.user.syuser
            )
            cr.save() 
                
        return response

class ProductDelete(DeleteView):
    model = Product
    context_object_name = "product_detail"
    template_name = "product/product_confirm_delete.html"
   
    """
    Return back to product list after successfully deleted selected object
    """
    def get_success_url(self):
        return reverse('oms:ProductList')

    def get_context_data(self, **kwargs):
        context = super(ProductDelete, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        return context

################################################################################################
# Add item into the cart
#
################################################################################################

class CartItemCreate(CreateView):

    model = CartItem
    fields = ['quantity_wanted',]
    template_name = "order/cartitem_creation.html"

    """
    Return back to product list after successfully deleted selected object
    """
    def get_success_url(self):
        return reverse('oms:ProductList')

    def get_context_data(self, **kwargs):
        context = super(CartItemCreate, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        
        # get() works here. filter() doesn't work. A little difference between get() and filter()
        try:
            detail = Product.objects.get(pk=self.kwargs['pk'])            
        except Product.DoesNotExist:
            raise Http404("Product doesn't exist")
        if not detail:
            raise Http404("Specified product doesn't exist")
        context['product_detail'] = detail
        return context
    
    """
    A little tricky here. Get the object from form.save(commit = False). Then call super().form_valid().
    """
    def form_valid(self, form):

        # Need to check whether the product already in shopping cart
        temp_pro = Product.objects.get(pk = self.kwargs['pk'])
        if temp_pro:
            items = CartItem.objects.filter(pro_selected = temp_pro, user_rec = self.request.user.syuser, order_rec__isnull = True)

        # set product id, user id automatically, only quantity required could be set by retailer
        obj = form.save(commit = False)
        obj.pro_selected = get_object_or_404(Product, pk = self.kwargs['pk'])

        if form.cleaned_data['quantity_wanted'] <= 0:
            form.add_error('quantity_wanted', '订购数量必须是整数')
            return self.form_invalid(form)

        left = obj.pro_selected.quantity - obj.pro_selected.reserved_quantity
        if left < form.cleaned_data['quantity_wanted'] :
            msg = "库存仅剩"+ str(left)
            form.add_error('quantity_wanted', msg)
            return self.form_invalid(form)
        obj.user_rec = self.request.user.syuser

        # Very tricky here, remove duplicate ones firstly, then save current object.
        if items:
            for item in items:
                item.delete()

        response = super(CartItemCreate, self).form_valid(form)
        return response


####################################################################################################
# In order to update multiple objects with different value in one page, need to use FormSet.
# Noted: UpdateView is only applicable for single object.
#
####################################################################################################
def cartitems_list(request):

    CartItemFormSet = modelformset_factory(model = CartItem, form = CartItemForm,
        formset = BaseCartItemFormSet, extra = 0, can_delete = True)
    if request.method == 'POST':
        formset = CartItemFormSet(request.POST, request.FILES)
        if formset.is_valid():
            formset.save()
            # validation check passed, need to redirect to order creation page
            return HttpResponseRedirect(reverse('oms:OrderCreate'))
        else:
            print("cartitems_list(),validation error.")
    else:
        formset = CartItemFormSet(queryset = CartItem.objects.filter(order_rec__isnull = True, user_rec = request.user.syuser))
    return render(request, 'order/cartitems_list.html',
        {'formset': formset, 'username': request.user.username, 'count': formset.total_form_count()})

        
class OrderList(generic.ListView):
    model = Order
    template_name = "order/order_list.html"
    context_object_name = 'order_list'

    """
    A little interesting here. Using class based views, if need to retrieve more information, the attribute should
    be set in context. Then in html template, the value could be used directly as context_object_name.
    """
    def get_context_data(self, **kwargs):
        context = super(OrderList, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        context['user'] = self.request.user
        return context
    
    def get_queryset(self):

        try:
            if self.request.user.syuser.is_admin():
                # filter out orders not submitted
                ordList = Order.objects.filter(submitted_date__isnull = False)
            elif self.request.user.syuser.is_retailer():
                ordList = Order.objects.filter(user_rec = self.request.user.syuser)
            else:
                raise Http404("You're not permitted to review Order list here.")
            
        except Product.DoesNotExist:
            raise Http404("Product information doesn't exist")
        
        orConL = [] 
        for item in ordList:
            orCon = OrderContent(item.id, item.created_date, item.submitted_date, item.confirmed_date, 
                item.canceled_date, item.transport_number)
            orCon.getStatus()
            orConL.append(orCon)

        # show 15 records per page
        paginator = Paginator(orConL, 15)
        page = self.request.GET.get('page') 
        try:
            prots = paginator.page(page)
        except PageNotAnInteger:
            # If page is not an integer, deliver first page.
            prots = paginator.page(1)
        except EmptyPage:
            # If page is out of range (e.g. 9999), deliver last page of results.
            prots = paginator.page(paginator.num_pages)

        return prots

################################################################################
# Order creation page 
# Provide final cost and goods list for user to confirm and place order
################################################################################
class OrderCreate(CreateView):
    model = Order
    fields = ['deliver_addr']
    template_name = "order/order_creation.html"

    cart = ShoppingCart_Cost()
    def get_context_data(self, **kwargs):
        context = super(OrderCreate, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        # need to get the items which are put into shopping cart
        try:
            logUserN = self.request.user.syuser
            context['retailers'] = RetailerInfo.objects.filter(user_rec = logUserN)
            items = CartItem.objects.filter(user_rec = logUserN, order_rec__isnull = True)
        except CartItem.DoesNotExist:
            raise Http404("CartItem doesn't exist")
   
        # if cart is empty, redirect customer to product list to place order.
        if len(items) == 0:
            context['cart_empty'] = True
        
        """
        Noted: Need to reinitialize cart here, as if user select return back to shopping cart to modify,
               then this page is called recursively.
        """
        self.cart.clear()
        if items:
            for item in items:
                obj_order_cost = Good_Cost(item.pro_selected, item.pro_selected.price, item.quantity_wanted,
                    item.pro_selected.discount)
                self.cart.add(obj_order_cost)

        for item in self.cart.set:
            item.getCost()
        
        self.cart.getProductCost()
        context['cart'] = self.cart
        return context

    # need to custom form_valid
    def form_valid(self, form):
        """
        Noted: form only carry deliver_addr back, need to set other attribute here
               Also need to update order field in related cart items 
        """
        obj = form.save(commit = False)   
        obj.product_cost = self.cart.getProductCost()
        obj.total_cost = self.cart.getFinalCost()
        obj.user_rec = self.request.user.syuser
        obj.create_date = timezone.now()
        response = super(OrderCreate, self).form_valid(form)
  
        """
        items in cart should be updated with order id. Reserved quantity in related product should
        also be updated to reflect real situation.
        """
        items = CartItem.objects.filter(user_rec = self.request.user.syuser, order_rec__isnull = True)
        for item in items:
            item.order_rec = form.instance
            item.save()
        
        return response   

class OrderSubmit(UpdateView):
    model = Order
    fields = ['deliver_addr']
    template_name = "order/order_submit.html"
    context_object_name = 'order_detail'

    cart = ShoppingCart_Cost()

    """
    Return back to product list after successfully deleted selected object
    """
    def get_success_url(self):
        #return reverse('oms:OrderDetail', args = [self.object.id,])
        return reverse('oms:OrderDetail', kwargs = {'pk' : self.object.id,})

    def get_context_data(self, **kwargs):
        context = super(OrderSubmit, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username

        try:
            logUserN = self.request.user.syuser
            context['retailers'] = RetailerInfo.objects.filter(user_rec = logUserN)
            items = CartItem.objects.filter(user_rec = logUserN, order_rec = self.object.id)
        except CartItem.DoesNotExist:
            raise Http404("CartItem doesn't exist")

        if not items:
            raise Http404("Shopping cart is empty.")
        
        self.cart.clear()
        for item in items:
            obj_order_cost = Good_Cost(item.pro_selected, item.pro_selected.price, item.quantity_wanted,
                item.pro_selected.discount)
            self.cart.add(obj_order_cost)

        for item in self.cart.set:
            item.getCost()
        
        self.cart.getProductCost()
        context['cart'] = self.cart

        return context

    def form_valid(self, form):
        obj = form.save(commit=False)
        obj.submitted_date = timezone.now()
        
        response = super(OrderSubmit, self).form_valid(form)
  
        """
        Reserved quantity in related product should be updated to reflect real situation.
        """
        items = CartItem.objects.filter(user_rec = self.request.user.syuser, order_rec = self.object.id)
        for item in items:
            item.pro_selected.reserved_quantity += item.quantity_wanted
            item.pro_selected.save()

        return response

class OrderConfirmation(UpdateView):
    model = Order
    fields = ['transport_number']
    template_name = "order/order_confirmation.html"
    context_object_name = 'order_detail'
    
    cart = ShoppingCart_Cost()

    """
    Return back to product list after successfully deleted selected object
    """
    def get_success_url(self):
        return reverse('oms:OrderDetail', kwargs = {'pk' : self.object.id,})

    def get_context_data(self, **kwargs):
        context = super(OrderConfirmation, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username

        try:
            logUserN = self.request.user.syuser
            context['retailers'] = RetailerInfo.objects.filter(user_rec = logUserN)
            items = CartItem.objects.filter(order_rec = self.object.id)
        except CartItem.DoesNotExist:
            raise Http404("CartItem doesn't exist")

        if not items:
            print("OrderConfirmation: No goods in this order.")
        
        self.cart.clear()
        for item in items:
            obj_order_cost = Good_Cost(item.pro_selected, item.pro_selected.price, item.quantity_wanted,
                item.pro_selected.discount)
            self.cart.add(obj_order_cost)

        for item in self.cart.set:
            item.getCost()
        
        self.cart.getProductCost()

        context['cart'] = self.cart

        return context

    """
    Once order is confirmed, reserved part for this order should be deducted from the total quantity.
    """
    def form_valid(self, form):
        obj = form.save(commit=False)
        obj.confirmed_date = timezone.now()
        response = super(OrderConfirmation, self).form_valid(form)
        items = CartItem.objects.filter(order_rec = self.object.id)
        for item in items:
            item.pro_selected.quantity -= item.quantity_wanted
            item.pro_selected.reserved_quantity -= item.quantity_wanted
            item.pro_selected.save()
        return response

class OrderCanceled(UpdateView):
    model = Order
    fields = ['transport_number']
    context_object_name = 'order_detail'
    template_name = "order/order_canceled.html"
   
    def get_success_url(self):
        return reverse('oms:OrderList')

    def get_context_data(self, **kwargs):
        context = super(OrderCanceled, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username

        try:
            logUserN = self.request.user.syuser
            context['retailers'] = RetailerInfo.objects.filter(user_rec = logUserN)
            items = CartItem.objects.filter(user_rec = logUserN, order_rec = self.object.id)
        except CartItem.DoesNotExist:
            raise Http404("CartItem doesn't exist")

        if not items:
            print("Shopping cart is empty.")
        
        context['items'] = items
        return context

    # Once order is canceled, reserved quantity should be updated.
    def form_valid(self, form):
        obj = form.save(commit=False)
        obj.canceled_date = timezone.now()
        response = super(OrderCanceled, self).form_valid(form)
        items = CartItem.objects.filter(order_rec = self.object.id)
        for item in items:
            item.pro_selected.reserved_quantity -= item.quantity_wanted
            item.pro_selected.save()
        return response

class OrderDelete(DeleteView):
    model = Order
    context_object_name = 'order_detail'
    template_name = "order/order_confirm_delete.html"
   
    def get_success_url(self):
        return reverse('oms:OrderList')

    def get_context_data(self, **kwargs):
        context = super(OrderDelete, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username

        try:
            logUserN = self.request.user.syuser
            context['retailers'] = RetailerInfo.objects.filter(user_rec = logUserN)
            items = CartItem.objects.filter(user_rec = logUserN, order_rec = self.object.id)
        except CartItem.DoesNotExist:
            raise Http404("CartItem doesn't exist")

        if not items:
            print("Shopping cart is empty.")
        
        context['items'] = items
        return context

class OrderDetail(generic.DetailView):
    model = Order
    template_name = "order/order_detail.html"
    context_object_name = 'order_detail'

    cart = ShoppingCart_Cost()

    def get_queryset(self):
        try:
            detail = Order.objects.filter(pk=self.kwargs['pk'])
        except Order.DoesNotExist:
            raise Http404("Order doesn't exist")
        if not detail:
            raise Http404("Order doesn't exist")
        
        return detail

    def get_context_data(self, **kwargs):
        context = super(OrderDetail, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        items = CartItem.objects.filter(order_rec = context['order_detail'])
        context['items'] = items

        self.cart.clear()
        for item in items:
            obj_order_cost = Good_Cost(item.pro_selected, item.pro_selected.price, item.quantity_wanted,
                item.pro_selected.discount)
            self.cart.add(obj_order_cost)

        for item in self.cart.set:
            item.getCost()

        context['cart'] = self.cart

        return context


################################################################################################
# Following views are for RetailerInfo related operations.
#
################################################################################################
class RetailerInfoList(generic.ListView):
    template_name = "retailer/retailerinfo_list.html"
    context_object_name = 'retailerinfo_list'

    """
    A little interesting here. Using class based views, if need to retrieve more information, the attribute should
    be set in context. Then in html template, the value could be used directly as context_object_name.
    """
    def get_context_data(self, **kwargs):
        context = super(RetailerInfoList, self).get_context_data(**kwargs)
        context['user'] = self.request.user
        context['username'] = self.request.user.username
        return context
    
    def get_queryset(self):

        try:
            reList = RetailerInfo.objects.filter(user_rec = self.request.user.syuser)
        except Product.DoesNotExist:
            raise Http404("Retailer information doesn't exist")
        
        # show 15 records per page
        paginator = Paginator(reList, 15)
        page = self.request.GET.get('page') 
        try:
            retailers = paginator.page(page)
        except PageNotAnInteger:
            # If page is not an integer, deliver first page.
            retailers = paginator.page(1)
        except EmptyPage:
            # If page is out of range (e.g. 9999), deliver last page of results.
            retailers = paginator.page(paginator.num_pages)

        return retailers
            
class RetailerInfoCreation(CreateView):
    model = RetailerInfo
    fields = ['retailer_name', 'phone', 'address' ]
    template_name = "retailer/retailerinfo_creation.html"
    
    def get_context_data(self, **kwargs):
        context = super(RetailerInfoCreation, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        return context

    """
    When Product is created, want to create related history record automatically.
    Need to overwrite form_valid()
    """
    def form_valid(self, form):
        obj = form.save(commit = False)
        obj.user_rec = self.request.user.syuser
        response = super(RetailerInfoCreation, self).form_valid(form)

        return response
        
class RetailerInfoUpdate(UpdateView):
    model = RetailerInfo
    fields = ['retailer_name', 'phone', 'address']
    template_name = "retailer/retailerinfo_update.html"

    def get_success_url(self):
        return reverse('oms:RetailerInfoList')

    def get_context_data(self, **kwargs):
        context = super(RetailerInfoUpdate, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        return context

    def form_valid(self, form):
        response = super(RetailerInfoUpdate, self).form_valid(form)
        return response

class RetailerInfoDelete(DeleteView):
    model = RetailerInfo
    context_object_name = "retailerinfo_detail"
    template_name = "retailer/retailerinfo_confirm_delete.html"
   
    def get_success_url(self):
        return reverse('oms:RetailerInfoList')

    def get_context_data(self, **kwargs):
        context = super(RetailerInfoDelete, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        return context

class RetailerInfoDetail(generic.DetailView):
    template_name = "retailer/retailerinfo_detail.html"
    context_object_name = "retailerinfo_detail"

    def get_queryset(self):
        try:
            detail = RetailerInfo.objects.filter(pk=self.kwargs['pk'])            
        except Product.DoesNotExist:
            raise Http404("RetailerInfo doesn't exist")
        if not detail:
            raise Http404("Specified RetailerInfo doesn't exist")
        return detail

    def get_context_data(self, **kwargs):
        context = super(RetailerInfoDetail, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        return context

