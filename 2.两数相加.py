# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def makelist(self,num:int) -> ListNode:
        if num==0:
            list=ListNode(0)
            return list
        first=ListNode(0)
        temp=first
        while not num==0:
            toadd=num%10
            num=num//10
            list=ListNode(toadd)
            temp.next=list
            temp=list
        return first.next



    def calnum(self,l1:ListNode) -> int:
        num=0
        base=1
        while True:
            num+=l1.val*base
            base*=10
            if not l1.next==None:
                l1=l1.next
            else:
                print(num)
                return num
            
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        num1=self.calnum(l1)
        num2=self.calnum(l2)
        sum=num1+num2
        return self.makelist(sum)