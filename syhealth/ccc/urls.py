###############################################################################
# Written by Jared on May 14, 2016.
# All rights reserved.
#
# This file is URLs for customer care center.
#
###############################################################################

from django.conf.urls import url
from django.contrib.auth import views as auth_views

# below is for debug only
from django.conf.urls.static import static
from django.conf import settings


from . import views

app_name = 'ccc'

urlpatterns = [
    url(r'^$', auth_views.login, 
        {'template_name' : 'registration/login_ccc.html'},
        name = 'index',
    ),
    url(r'^login/$', auth_views.login, 
        {'template_name' : 'registration/login_ccc.html'},
        name = 'UserLogin',
    ),
    url(r'^logout/$', auth_views.logout, 
        {'template_name' : 'registration/logout_ccc.html'},
        name = 'UserLogout'),

    url(r'^change_password/$', auth_views.password_change, 
        {'post_change_redirect' : 'ccc:UserPasswdChanged',
        'template_name' : 'registration/passwd_ccc_form.html'},
        name = 'UserChangePasswd'),
    url(r'^password_change/done/$', auth_views.password_change_done,
        {'template_name' : 'registration/passwd_ccc_done.html'},
        name='UserPasswdChanged'),

    url(r'^customerinfo/list/$', views.CustomerInfoList.as_view(), name = 'CustomerInfoList'),
    url(r'^customerinfo/create/$', views.CustomerInfoCreate.as_view(), name = 'CustomerInfoCreate'),
    url(r'^customerinfo/update/id=(?P<pk>[0-9]+)/$', views.CustomerInfoUpdate.as_view(), name = 'CustomerInfoUpdate'),
    url(r'^customerinfo/detail/id=(?P<pk>[0-9]+)/$', views.CustomerInfoDetail.as_view(), name = 'CustomerInfoDetail'),

    url(r'^customerfeedback/list/custid=(?P<pk>[0-9]+)/$', views.CustomerFeedbackList.as_view(),
        name = 'CustomerFeedbackList'),
    url(r'^customerfeedback/create/custid=(?P<pk>[0-9]+)/$', views.CustomerFeedbackCreate.as_view(),
        name = 'CustomerFeedbackCreate'),
    url(r'^customerfeedback/update/feedid=(?P<pk>[0-9]+)/cust_id=(?P<cust_id>[0-9]+)/$', views.CustomerFeedbackUpdate.as_view(),
        name = 'CustomerFeedbackUpdate'),
    url(r'^customerfeedback/delete/feed_id=(?P<pk>[0-9]+)/cust_id=(?P<cust_id>[0-9]+)/$', views.CustomerFeedbackDelete.as_view(),
        name = 'CustomerFeedbackDelete'),
    url(r'^customerfeedback/detail/feed_id=(?P<pk>[0-9]+)/cust_id=(?P<cust_id>[0-9]+)/$', views.CustomerFeedbackDetail.as_view(),
        name = 'CustomerFeedbackDetail'),

] 
# + static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)

"""
Noted: last line similar as static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)
is used for debugging purpose only.
"""
