###################################################################################
# Written by Jared on April 5, 2016.
# All rights reserved.
###################################################################################

from django.conf.urls import url
from . import views

# customer log in required
from django.contrib.auth import views as auth_views
#from django.contrib.auth import logout

app_name = 'oms'

urlpatterns = [

    ####################################################################################################
    # Following urls for login, log out and passord change.
    # Noted: Here we make use of login, logout and password_change from package of auth.views.
    # Need to follow the usage and pass parameters if necessary.
    # For example, password_change need parameter named 'post_change_redirect' to determine the redirect
    # information after password changed successfully.
    # For similar information, we could find them in django source code.
    ####################################################################################################

    url(r'^$', auth_views.login, 
        {'template_name' : 'registration/login_oms.html'},
        name = 'index'),
    url(r'^login/$', auth_views.login, 
        {'template_name' : 'registration/login_oms.html'},
        name = 'UserLogin'),
    url(r'^logout/$', auth_views.logout, 
        {'template_name' : 'registration/logout_oms.html'},
        name = 'UserLogout',),
    url(r'^change_password/$', auth_views.password_change, {'post_change_redirect' : 'oms:UserPasswdChanged',},
        name = 'UserChangePasswd'),
    url(r'^password_change/done/$', auth_views.password_change_done, name='UserPasswdChanged'),
    url(r'^userprofile/user=(?P<username>\w+)/$', auth_views.login, name = 'UserProfile'),

    # following usrls for products
    url(r'oms/products/$', views.ProductList.as_view(), name = 'ProductList'),
    url(r'oms/product/create/$', views.ProductCreation.as_view(), name='ProductCreation'),
    url(r'oms/product/delete/id=(?P<pk>[0-9]+)/$', views.ProductDelete.as_view(), name = 'ProductDelete'),
    url(r'oms/product/update/id=(?P<pk>[0-9]+)/$', views.ProductUpdate.as_view(), name = 'ProductUpdate'),
    url(r'oms/product/detail/product=(?P<pk>[0-9]+)/$', views.ProductDetail.as_view(), name = 'ProductDetail'),

    # following urls for retailer info
    url(r'oms/retailerinfo/$', views.RetailerInfoList.as_view(), name = 'RetailerInfoList'),
    url(r'oms/retailerinfo/create/$', views.RetailerInfoCreation.as_view(), name = 'RetailerInfoCreate'),
    url(r'oms/retailerinfo/update/id=(?P<pk>[0-9]+)/$', views.RetailerInfoUpdate.as_view(), name = 'RetailerInfoUpdate'),
    url(r'oms/retailerinfo/delete/id=(?P<pk>[0-9]+)/$', views.RetailerInfoDelete.as_view(), name = 'RetailerInfoDelete'),
    url(r'oms/retailerinfo/id=(?P<pk>[0-9]+)/$', views.RetailerInfoDetail.as_view(), name = 'RetailerInfoDetail'),

    # following urls for cart items
    url(r'oms/cart/cartitems/$', views.cartitems_list, name = 'CartItemList'),
    url(r'oms/cart/addproduct/id=(?P<pk>[0-9]+)/$', views.CartItemCreate.as_view(), name = 'CartItemCreate'),

    # following urls for order 
    url(r'oms/order/list/$', views.OrderList.as_view(), name = 'OrderList'),
    url(r'oms/order/create/$', views.OrderCreate.as_view(), name = 'OrderCreate'),
    url(r'oms/order/submit/id=(?P<pk>[0-9]+)/$', views.OrderSubmit.as_view(), name = 'OrderSubmit'),
    url(r'oms/order/delete/id=(?P<pk>[0-9]+)/$', views.OrderDelete.as_view(), name = 'OrderDelete'),
    url(r'oms/order/id=(?P<pk>[0-9]+)/$', views.OrderDetail.as_view(), name = 'OrderDetail'),

    url(r'oms/order/confirm/id=(?P<pk>[0-9]+)/$', views.OrderConfirmation.as_view(), name = 'OrderConfirmation'),
    url(r'oms/order/cancel/id=(?P<pk>[0-9]+)/$', views.OrderCanceled.as_view(), name = 'OrderCanceled'),
    

]

