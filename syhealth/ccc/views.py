##############################################################################
# Written by Jared on May 25, 2016.
# All rights reserved.
##############################################################################
from django.shortcuts import render

# Create your views here.
import os
from django.conf import settings
from django.utils import timezone
from django.views import generic
from django.views.generic.edit import CreateView, UpdateView, DeleteView
from django.core.paginator import Paginator, EmptyPage, PageNotAnInteger
from django.core.exceptions import ValidationError
from django.http import Http404
from django.core.urlresolvers import reverse

from .models import CustomerInfo, SYUser, CustomerFeedback
from .utility import rebuildPathname

class CustomerInfoList(generic.ListView):
    model = CustomerInfo
    template_name = 'customerinfo/customerinfo_list.html'
    context_object_name  = 'customerinfo_list'

    def get_context_data(self, **kwargs):
        context = super(CustomerInfoList, self).get_context_data(**kwargs)
        context['user'] = self.request.user
        return context

    def get_queryset(self):

        try:
            # for admin user, all the customers should be retrieved
            if self.request.user.syuser.is_admin():
                custList = CustomerInfo.objects.all()
            elif self.request.user.syuser.is_customer():
                custList = CustomerInfo.objects.filter(user_rec = self.request.user.syuser)
            else:
                raise Http404("You do not have the permission to access resource here")
        except CustomerInfo.DoesNotExist:
            raise Http404("No information was retrieved")

        # show 15 records per page
        paginator = Paginator(custList, 15)
        page = self.request.GET.get('page')
        try:
            custs = paginator.page(page)
        except PageNotAnInteger:
            # If page is not an integer, deliver first page.
            custs = paginator.page(1)
        except EmptyPage:
            # If page is out of range (e.g. 9999), deliver last page of results.
            custs = paginator.page(paginator.num_pages)

        return custs

class CustomerInfoCreate(CreateView):
    model = CustomerInfo
    template_name = 'customerinfo/customerinfo_create.html'
    fields = ['user_rec',
        'name', 'gender', 'birth_date', 'phone_number', 'date_joined',
        'weight', 'height', 
        'hr', 'sbp', 'dbp', 
        'tc', 'tg', 'hdl', 'ldl', 
        'glu', 'fbg', 'pbg', 'a1c',
        'ir', 'hcy', 'bua', 'vfp',
        'imt', 'up', 'lf', 'rf', 'uran', 'ba',
        'cons', 'frve', 'dietfood',
        'cdh', 'ph', 'fh', 'oh',
        'au', 'ecg',
    ]

    def get_context_data(self, **kwargs):
        context = super(CustomerInfoCreate, self).get_context_data(**kwargs)
        context['user'] = self.request.user
        return context

    def form_valid(self, form):
        obj = form.save(commit=False)
        obj.user_rec = self.request.user.syuser
        obj.calculate_bmi()
        
        response = super(CustomerInfoCreate, self).form_valid(form)

        # Need to rebuild filename and path for ekg and abdominal_sufficiency and update object
        obj = CustomerInfo.objects.get(pk=form.instance.id)
        updated = False
        if obj.au.name:
            tmpPath = rebuildPathname(obj.au.path, obj.name)
            os.rename(obj.au.path, tmpPath)
            obj.au = 'au/' + os.path.basename(tmpPath)
            updated = True

        if obj.ecg.name:
            tmpPath = rebuildPathname(obj.ecg.path, obj.name)
            os.rename(obj.ecg.path, tmpPath)
            obj.ecg = 'ecg/'+ os.path.basename(tmpPath)
            updated = True
         
        if updated == True:
            obj.save()

        """ need to record history for item creation
        cr = OperationHistory.objects.create(
            rec_pro = self.object,
            cr_reason = str(self.object) + " 创建成功.",
            user_admin = self.request.user
        )
        cr.save()
        """

        return response

class CustomerInfoDetail(generic.DetailView):
    model = CustomerInfo
    template_name = 'customerinfo/customerinfo_detail.html'
    context_object_name = "customerinfo_detail"

    def get_queryset(self):
        try:
            detail = CustomerInfo.objects.filter(pk=self.kwargs['pk'])
        except CustomerInfo.DoesNotExist:
            raise Http404("CustomerInfo doesn't exist")
        if not detail:
            raise Http404("Specified customer information doesn't exist")
        return detail

    def get_context_data(self, **kwargs):
        context = super(CustomerInfoDetail, self).get_context_data(**kwargs)
        context['user'] = self.request.user
        return context

class CustomerInfoUpdate(generic.UpdateView):
    model = CustomerInfo
    template_name = 'customerinfo/customerinfo_update.html'
    context_object_name = 'cust'

    fields = [ 'user_rec',
        'weight', 'height', 
        'hr', 'sbp', 'dbp', 
        'tc', 'tg', 'hdl', 'ldl', 
        'glu', 'fbg', 'pbg', 'a1c',
        'ir', 'hcy', 'bua', 'vfp',
        'imt', 'up', 'lf', 'rf', 'uran', 'ba',
        'cons', 'frve', 'dietfood',
        'cdh', 'ph', 'fh', 'oh',
        'au', 'ecg',
    ]

    def get_queryset(self):
        try:
            detail = CustomerInfo.objects.filter(pk=self.kwargs['pk'])
        except CustomerInfo.DoesNotExist:
            raise Http404("CustomerInfo doesn't exist")
        if not detail:
            raise Http404("Specified customer information doesn't exist")
        self.auName = detail[0].au.name
        self.ecgName = detail[0].ecg.name
        return detail

    def get_context_data(self, **kwargs):
        context = super(CustomerInfoUpdate, self).get_context_data(**kwargs)
        context['user'] = self.request.user
        return context

    def form_valid(self, form):
        
        response = super(CustomerInfoUpdate, self).form_valid(form)

        # Need to rebuild filename and path for ekg and abdominal_sufficiency and update object
        # if value is not changed, avoid rebuild and update path.
        obj = CustomerInfo.objects.get(pk=form.instance.id)
        updated = False
        if obj.au.name and obj.au.name != self.auName:
            tmpPath = rebuildPathname(obj.au.path, obj.name)
            os.rename(obj.au.path, tmpPath)
            obj.au = 'au/' + os.path.basename(tmpPath)
            updated = True

        if obj.ecg.name and obj.ecg.name != self.ecgName:
            tmpPath = rebuildPathname(obj.ecg.path, obj.name)
            os.rename(obj.ecg.path, tmpPath)
            obj.ecg = 'ecg/'+ os.path.basename(tmpPath)
            updated = True
         
        if updated == True:
            obj.save()

        return response

             
class CustomerFeedbackList(generic.ListView):
    model = CustomerFeedback
    template_name = 'customerinfo/feedback_list.html'
    context_object_name  = 'feedbacks'

    def get_context_data(self, **kwargs):
        context = super(CustomerFeedbackList, self).get_context_data(**kwargs)
        context['user'] = self.request.user
        context['cust_id'] = self.kwargs['pk']
        context['cust_name'] = self.cust.name
        return context

    def get_queryset(self):

        try:
            # for admin user, all the customers should be retrieved
            if self.request.user.syuser.is_admin() or self.request.user.syuser.is_customer():
                cus = CustomerInfo.objects.get(pk = self.kwargs['pk'])
                fbackList = CustomerFeedback.objects.filter(cust_info = cus)
                self.cust = cus
            else:
                raise Http404("You do not have the permission to review CustomerFeedback information here.")
        except CustomerFeedback.DoesNotExist:
            raise Http404("No information was retrieved")

        # show 15 records per page
        paginator = Paginator(fbackList, 15)
        page = self.request.GET.get('page')
        try:
            custs = paginator.page(page)
        except PageNotAnInteger:
            # If page is not an integer, deliver first page.
            custs = paginator.page(1)
        except EmptyPage:
            # If page is out of range (e.g. 9999), deliver last page of results.
            custs = paginator.page(paginator.num_pages)

        return custs

class CustomerFeedbackCreate(CreateView):
    model = CustomerFeedback
    template_name = 'customerinfo/feedback_create.html'
    fields = ['feed_date', 'fv', 'weight', 
        'bp_time', 'sbp', 'dbp', 
        'fbg', 'pbg', 'bg_time',
        'sports_time',
        'op_react', 'other_dis', 'feedback'
    ]

    def get_context_data(self, **kwargs):
        context = super(CustomerFeedbackCreate, self).get_context_data(**kwargs)
        context['user'] = self.request.user
        return context

    def form_valid(self, form):
        obj = form.save(commit=False)
        
        # need to set custoemrinfo 
        obj.cust_info = CustomerInfo.objects.get(pk=self.kwargs['pk'])
        response = super(CustomerFeedbackCreate, self).form_valid(form)

        """ need to record history for item creation
        cr = OperationHistory.objects.create(
            rec_pro = self.object,
            cr_reason = str(self.object) + " 创建成功.",
            user_admin = self.request.user
        )
        cr.save()
        """

        return response

class CustomerFeedbackUpdate(UpdateView):
    model = CustomerFeedback
    template_name = 'customerinfo/feedback_update.html'
    fields = ['feed_date', 'fv', 'weight', 
        'bp_time', 'sbp', 'dbp', 
        'fbg', 'pbg', 'bg_time',
        'sports_time',
        'op_react', 'other_dis', 'feedback'
    ]

    def get_context_data(self, **kwargs):
        context = super(CustomerFeedbackUpdate, self).get_context_data(**kwargs)
        context['user'] = self.request.user
        context['cust_id'] = self.kwargs['cust_id']
        context['cust_name'] = self.cust.name
        return context

    def get_queryset(self):
        try:
            self.cust = CustomerInfo.objects.get(pk=self.kwargs['cust_id'])
            detail = CustomerFeedback.objects.filter(pk=self.kwargs['pk'])
        except CustomerFeedback.DoesNotExist:
            raise Http404("CustomerFeedback doesn't exist")
        if not detail:
            raise Http404("Specified customer information doesn't exist")
        return detail

class CustomerFeedbackDelete(DeleteView):
    model = CustomerFeedback
    context_object_name = "detail"
    template_name = "customerinfo/feedback_confirm_delete.html"
  
    """
    Return back to product list after successfully deleted selected object
    """
    def get_success_url(self):
        return reverse('ccc:CustomerFeedbackList', kwargs={'pk':self.kwargs['cust_id']})

    def get_context_data(self, **kwargs):
        context = super(CustomerFeedbackDelete, self).get_context_data(**kwargs)
        context['username'] = self.request.user.username
        context['cust_id'] = self.kwargs['cust_id']
        return context

class CustomerFeedbackDetail(generic.DetailView):
    model = CustomerFeedback
    template_name = 'customerinfo/feedback_detail.html'
    context_object_name = "detail"

    def get_queryset(self):
        try:
            self.cust = CustomerInfo.objects.get(pk=self.kwargs['cust_id'])
            detail = CustomerFeedback.objects.filter(pk=self.kwargs['pk'])
        except CustomerFeedback.DoesNotExist:
            raise Http404("CustomerInfo doesn't exist")
        if not detail:
            raise Http404("Specified customer information doesn't exist")
        return detail

    def get_context_data(self, **kwargs):
        context = super(CustomerFeedbackDetail, self).get_context_data(**kwargs)
        context['user'] = self.request.user
        context['cust_id'] = self.cust.id
        context['cust_name'] = self.cust.name
        return context


