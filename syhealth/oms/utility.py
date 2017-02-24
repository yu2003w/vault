###########################################################################
# Written by Jared on April 21, 2016.
# All rights reserved.
#
#
# This part of python code provide some functionality to handle real
# logic independent of view, model and control.
# This is not covered by real database structure. It intends to process
# OMS logic here.
###########################################################################

"""
This class is used to calculate final cost before order creation for one
kind of goods.

"""
class Good_Cost:
    def __init__(self, name, price, quantity, discount):
        self.name = name
        self.price = price
        self.quantity = quantity
        self.discount = discount
        self.cost = round(self.quantity * self.price * self.discount, 2)
    
    def getCost(self):
        return self.cost

class ShoppingCart_Cost:

    def __init__(self):
        self.set = set()
        self.product_cost = 0
        self.total_cost = 0

    def add(self, good_cost):
        self.set.add(good_cost)

    def getProductCost(self):
        self.product_cost = 0
        for item in self.set:
            self.product_cost += item.getCost()
        return self.product_cost
     
    def getFinalCost(self):
        self.total_cost = self.product_cost
        return self.total_cost

    def clear(self):
        self.total_cost = 0
        self.product_cost = 0
        self.set.clear()

##################################################################################
#In database, there is only submitted_date, confirmed_date for Order.
#Four status is defined for Order:
#Draft,
#Confirmed,
#GoodsDelivered,
#Completed.
#
#First two status should be set based on submitted_date and confirmed_date.
#Confirmed and GoodsDelivered should be set by Admin.
#Complete is set by system automatically.
#####################################################################################
class OrderContent:

    def __init__(self, id, created_date, submitted_date, confirmed_date, canceled_date, transport_num): 
        self.id = id
        self.created_date = created_date
        self.submitted_date = submitted_date
        self.transport_number = transport_num
        self.confirmed_date = confirmed_date
        self.canceled_date = canceled_date

    def getStatus(self):
        if not self.submitted_date:
            self.status = u"未提交"
        elif self.canceled_date:
            self.status = u"订单已经取消"
        elif not self.confirmed_date:
            self.status = u"订单已提交，付款后将会人工审核，发货"
        elif not self.transport_number:
            self.status = u"订单已经通过审核，准备发货"
        else:
            self.status = u"订单已经发货"
 
class ItemInCart:
    
    def setItem(self, item):
        self.item = item 


