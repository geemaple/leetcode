# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        left = l1
        right = l2
        head = ListNode(0)
        cur = head
        
        while left is not None or right is not None:
            left_val = left.val if left is not None else float('inf')
            right_val = right.val if right is not None else float('inf')
            
            if left_val <= right_val:
                cur.next = left
                left = left.next
            else:
                cur.next = right
                right = right.next
                
            cur = cur.next
            
        return head.next