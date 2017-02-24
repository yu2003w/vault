#######################################################################################
# Written by Jared on May 14, 2016.
# All rights reserved.
#
# Models for customer care. Most important customer information is stored here.
#######################################################################################

from django.db import models

# added by Jared

from django.utils import timezone
from django.core.urlresolvers import reverse
from django.contrib.auth.models import User

# Create your models here.

"""
   need to extend user here to add additional attribute to indicate whether user is
   real customer, retailer, admin or any other type which maybe needed in future.
"""
class SYUser(models.Model):
    sy_type_choices = (
        # retailer
        ('R', '经销商'),
        # cusotomer
        ('C', '终端用户'),
        # administrator
        ('A', '管理员'),
    )
    user = models.OneToOneField(User, on_delete = models.CASCADE)
    user_type = models.CharField("用户类型", max_length = 1, choices = sy_type_choices)

    class Meta:
        verbose_name = "双圆健康用户"
    
    def is_admin(self):
        if self.user_type == 'A':
           return True
        return False

    def is_customer(self):
        if self.user_type == 'C':
           return True
        return False
   
    def is_retailer(self):
        if self.user_type == 'R':
           return True
        return False

    def __str__(self):
        return self.user.username


class CustomerInfo(models.Model):
    
    # for customer inforamtion, only real customers are available.
    # limit_choices_to could be used for filtering.
    user_rec = models.ForeignKey(SYUser, verbose_name = "用户名", limit_choices_to = {'user_type': 'C',})

    gender_type_choices = (
        ('M', '男'),
        ('F', '女'),
    )
   
    # basic personal informaiton 
    name = models.CharField("姓名", max_length = 64)
    gender = models.CharField("性别", max_length = 1,  choices = gender_type_choices, default = 'F')
    birth_date = models.DateField("出生日期")
    phone_number = models.CharField("电话号码", max_length = 15)
    date_joined = models.DateField("加入日期", default = timezone.now)

    weight = models.DecimalField("体重", max_digits = 5, decimal_places = 2, default = 0)
    height = models.DecimalField("身高", max_digits = 4, decimal_places = 1, default = 0)

    # noted: BMI value is calculated by service, no need to be inputted by admin
    bmi = models.DecimalField("BMI:(体重(KG)/身高×身高(M))", max_digits = 5, decimal_places = 2, default = 0.00)

    hr = models.DecimalField("心率", max_digits = 3, decimal_places = 0, default = 0)
    sbp = models.DecimalField("SBP（收缩压）", max_digits = 3, decimal_places = 0, default = 0)
    dbp = models.DecimalField("DBP（舒张压）", max_digits = 3, decimal_places = 0, default = 0)
    tc = models.DecimalField("TC（总胆固醇）", max_digits = 4, decimal_places = 2, default = 0)
    tg = models.DecimalField("TG（甘油三脂）", max_digits = 4, decimal_places = 2, default = 0)
    hdl = models.DecimalField("HDL（高密度脂蛋白）", max_digits = 4, decimal_places = 2, default = 0)
    ldl = models.DecimalField("LDL（低密度脂蛋白）", max_digits = 4, decimal_places = 2, default = 0)
    glu = models.DecimalField("GLU(随机血糖)", max_digits = 4, decimal_places = 2, default = 0)
    fbg = models.DecimalField("FBG(空腹血糖)", max_digits = 4, decimal_places = 2, default = 0)
    pbg = models.DecimalField("PBG(餐后血糖)", max_digits = 4, decimal_places = 2, default = 0)
    a1c = models.DecimalField("A1C", max_digits = 5, decimal_places = 2, default = 0)
    ir = models.DecimalField("胰岛素抵抗(IR)", max_digits = 5, decimal_places = 2, default = 0.00)
 
    hcy = models.DecimalField("同型半胱氨酸", max_digits = 5, decimal_places = 2, default = 0)
    bua = models.DecimalField("血尿酸", max_digits = 5, decimal_places = 2, default = 0)
    vfp = models.DecimalField("内脏脂肪占比", max_digits = 3, decimal_places = 2, default = 0)

    imt = models.CharField("IMT(颈动脉斑块)", max_length = 128, blank = True)
    up = models.CharField("尿蛋白", max_length = 128, blank = True)
    lf = models.CharField("肝功", max_length = 128, blank = True)
    rf = models.CharField("肾功", max_length = 128, blank = True)
    uran = models.TextField("尿液分析", max_length = 128, blank = True)
    ba = models.TextField("血液分析", max_length = 128, blank = True)
   
    cons = models.TextField("便秘", max_length = 64, blank = True)
    frve = models.TextField("蔬菜和水果", max_length = 128, blank = True)
    dietfood = models.TextField("忌口的食物", max_length = 128, blank = True)
    
    cdh = models.TextField("现病史", max_length = 512, blank = True)
    ph = models.TextField("既往史", max_length = 512, blank = True)
    fh = models.TextField("家族史", max_length = 512, blank = True)
    oh = models.TextField("手术史", max_length = 512, blank = True)
 
    au = models.ImageField("腹部彩超", upload_to='au/', blank = True)
    ecg = models.ImageField("心电图",upload_to='ecg/', blank = True)


    def __str__(self):
        return self.name   

    def calculate_bmi(self):
        # height is cm, need to convert to m to calculate BMI
        if self.height > 0:
            self.bmi = round(self.weight * 100 * 100 / (self.height * self.height), 2)

    def age(self):
        date_now = timezone.now()
        value_year = date_now.year - self.birth_date.year
        value_month = date_now.month - self.birth_date.month
        value_day = date_now.day - self.birth_date.day
        value_age = value_year 
        if value_month > 0:
            value_age = value_year
        elif value_month == 0:
            if value_day >= 0:
                value_age = value_year
            else:
                value_age = value_year - 1
        else:
            value_age = value_year - 1
        return value_age

    age.verbose_name = u'年龄'

    def get_absolute_url(self):
        return reverse('ccc:CustomerInfoDetail', kwargs={'pk':self.pk})


class CustomerFeedback(models.Model):

    cust_info = models.ForeignKey(CustomerInfo, verbose_name = "用户基本信息")

    feed_date = models.DateTimeField("反馈日期", default = timezone.now)
    fv = models.CharField("燃值", max_length = 64, blank = True)
    weight = models.DecimalField("体重", max_digits = 4, decimal_places = 1, default = 0)
    sbp = models.DecimalField("SBP（收缩压）", max_digits = 3, decimal_places = 0, default = 0)
    dbp = models.DecimalField("DBP（舒张压）", max_digits = 3, decimal_places = 0, default = 0)
    bp_time = models.TimeField("测量时间", default = timezone.now)
    fbg = models.DecimalField("FBG(空腹血糖)", max_digits = 4, decimal_places = 2, default = 0)
    pbg = models.DecimalField("PBG(餐后血糖)", max_digits = 4, decimal_places = 2, default = 0)
    bg_time = models.TimeField("测量时间", default = timezone.now)
    sports_time = models.TimeField("有氧运动时间", default = timezone.now)
    op_react = models.TextField("调理反应", max_length = 128, blank = True)
    other_dis = models.TextField("其它不适", max_length = 256, blank = True)
    feedback = models.TextField("体会及反馈", max_length = 256, blank = True)

    """
    A little tricky here, need to filter out feedback information both with customerinfo and 
    customerfeedback.
    """
    def get_absolute_url(self):
        return reverse('ccc:CustomerFeedbackDetail', kwargs={'pk':self.pk, 'cust_id':self.cust_info.id,})

