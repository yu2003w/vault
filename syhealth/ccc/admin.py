###################################################################################
# Written by Jared on May 16, 2016.
# All rights reserved.
###################################################################################
from django.contrib import admin
from django.contrib.auth.models import User
from django.contrib.auth.admin import UserAdmin

from .models import SYUser
# Register your models here.

class SYUserInline(admin.StackedInline):
    model = SYUser
    can_delete = False
    verbose_name_plural = '双圆健康用户类型'

class SYUserAdmin(UserAdmin):
    inlines = (SYUserInline, )

admin.site.unregister(User)
admin.site.register(User, SYUserAdmin)

