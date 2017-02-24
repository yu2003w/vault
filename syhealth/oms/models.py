########################################################################################
# Written by Jared on April 9, 2016.
# All rights reserved.
#
########################################################################################

from django.db import models

# Create your models here.
from django.utils import timezone
from django.core.urlresolvers import reverse
from django.contrib.auth.models import User

from ccc.models import SYUser

    
#########################################################################################
# RetailerInfo is required in order. 
# User may have several RetailerInfo.
#########################################################################################
class RetailerInfo(models.Model):
    user_rec = models.ForeignKey(SYUser, verbose_name = "用户")
    retailer_name = models.CharField("姓名", max_length = 64)
    phone = models.CharField("电话号码", max_length = 15)
    address = models.CharField("邮寄地址", max_length = 120)
 
    def get_absolute_url(self):
        return reverse('oms:RetailerInfoDetail', kwargs={'pk':self.pk})

########################################################################################
# Order information
# Once order is submitted by retailer, admin user will confirm it after retailer paid
#
########################################################################################
class Order(models.Model):
    user_rec = models.ForeignKey(SYUser, verbose_name="用户")
    created_date = models.DateTimeField("创建时间", default=timezone.now)
    submitted_date = models.DateTimeField("提交时间", null = True, blank = True)
    confirmed_date = models.DateTimeField("确认时间", null = True, blank = True)
    canceled_date = models.DateTimeField("取消时间", null = True, blank = True)
    product_cost = models.DecimalField("总计", max_digits = 8, decimal_places = 2, default = 0)
    transport_fee = models.DecimalField("运费", max_digits = 5, decimal_places = 2, default = 0)
    transport_number = models.CharField("快递单号", max_length = 128, blank = True)
    total_cost = models.DecimalField("订单总价（含运费）", max_digits = 8, decimal_places = 2, default = 0)
    deliver_addr = models.ForeignKey(RetailerInfo, verbose_name = "收货人信息")
    
    def get_absolute_url(self):
        return reverse('oms:OrderSubmit', kwargs={'pk':self.pk})

#########################################################################################
# Product information
#
#########################################################################################    
class Product(models.Model):
    product_name = models.CharField("产品名称", unique = True, max_length = 64,) 
    product_description = models.TextField("产品描述", max_length = 1024)
    quantity = models.DecimalField("库存数量", max_digits = 10, decimal_places = 0, default = 0)
    price = models.DecimalField("产品单价", max_digits = 8, decimal_places = 2, default = 0)
    discount = models.DecimalField("产品折扣", max_digits = 3, decimal_places = 2, default = 1.00)
    # reserved quantity is the number that submitted in order, however, not paid yet.
    # if order is cancelled, the related reserved quantity is deducted from reserved quantity.
    # if order is confirmed, the related reserved quantity is deducted from quantity.
    reserved_quantity = models.DecimalField("冻结数量", max_digits = 8, decimal_places = 0, default = 0)
    status = models.BooleanField("产品上架", default = True)

    """
    Need to overwrite this method to redirect to successful page.
    """
    def get_absolute_url(self):
        return reverse('oms:ProductDetail', kwargs={'pk':self.pk})

    def __str__(self):
        return self.product_name

##########################################################################################
# Items created for shopping cart
# Information about user id, product id, order id and quantity wanted
##########################################################################################
class CartItem(models.Model):
    pro_selected = models.ForeignKey(Product, verbose_name = "产品")
    user_rec = models.ForeignKey(SYUser, verbose_name = "用户",
        on_delete = models.CASCADE)
    # Null of order_rec indicates that items is in shopping cart
    order_rec = models.ForeignKey(Order, verbose_name = "订单号",
        on_delete = models.CASCADE, null = True)
    quantity_wanted = models.DecimalField("选购数量", max_digits = 5, decimal_places = 0, default = 0)
    
    
##########################################################################################
# Product changed history
# This model is used for tracking change history for product
##########################################################################################
class ProductCR(models.Model):
    rec_pro = models.ForeignKey(Product, verbose_name = "产品名称", 
        on_delete=models.CASCADE, null=True)
    updated_date = models.DateTimeField("修改时间", default = timezone.now)
    cr_reason = models.CharField("变更原因", max_length = 512)
    user_admin = models.ForeignKey(SYUser, verbose_name = "管理员")


