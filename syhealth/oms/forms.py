##################################################################
# Written by Jared on April 19, 2016.
# All rights reserved.
#
##################################################################

from django.forms import BaseModelFormSet, ModelForm
from django.core.exceptions import ValidationError
from .models import CartItem, Product


class CartItemForm(ModelForm):
    
    class Meta:
        model = CartItem
        """
        Noted: Need to pay more attention here. For fields, only editable field should be listed here. 
               As validation error maybe raised if non editable fields are listed out here.
        """
        fields = ['quantity_wanted',]
   
    # this will raise field errors
    def clean_quantity_wanted(self):
        tmp_quan = self.cleaned_data['quantity_wanted']
        # need to check the number, user could not place order with number 0 for any goods
        if tmp_quan <= 0:
            raise ValidationError("采购数量必须是整数")
        return tmp_quan
 
    # this will raise non field errors
    def clean(self):
        cleaned_data = super(CartItemForm,self).clean()
        if self._errors.get('quantity_wanted'):
            raise ValidationError('',)
        tmp_quan = cleaned_data.get('quantity_wanted')
        tmp_pro = (cleaned_data.get('id')).pro_selected
        total_quan = tmp_pro.quantity
        tmp_resv = tmp_pro.reserved_quantity
        left = total_quan - tmp_resv
        if left < tmp_quan:
            msg = '库存仅剩' + str(left)
            raise ValidationError(msg)
        return cleaned_data

class BaseCartItemFormSet(BaseModelFormSet):

    def __init__(self, *args, **kwargs):
        super(BaseCartItemFormSet, self).__init__(*args, **kwargs)


