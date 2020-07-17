
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def printList(self,l:ListNode) -> ListNode:
        while not l == None:
            print(l.val)
            l=l.next
        print('end')

    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        l=ListNode()
        start=l
        while (not l1==None) and (not l2==None):
            if l1.val<l2.val:
                l.next=l1
                l1=l1.next
                l=l.next
                l.next=None
            else:
                l.next=l2
                l2=l2.next
                l=l.next
                l.next=None
            self.printList(l)
        while not l1==None:
            l.next=l1
            l1=l1.next
            l=l.next
            l.next=None
        while not l2==None:
            l.next=l2
            l2=l2.next
            l=l.next
            l.next=None
        return start.next