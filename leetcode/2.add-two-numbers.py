# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        pre = head = ListNode()
        addition = 0
        
        while (l1 is not None or l2 is not None or addition > 0):
            num1 = 0 if l1 is None else l1.val
            num2 = 0 if l2 is None else l2.val
            
            total = num1 + num2 + addition
            addition = total // 10
            pre.next = ListNode(val = total % 10)
            
            pre = pre.next
            l1 = None if l1 is None else l1.next
            l2 = None if l2 is None else l2.next
            
        return head.next
