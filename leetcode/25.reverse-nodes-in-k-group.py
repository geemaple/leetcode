# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        
        if k < 2:
            return head
        
        cur = sentry = ListNode()
        sentry.next = head
        
        while cur is not None:
            cur = self.reverse(cur, k)
            
        return sentry.next
        
        
    def reverse(self, cur: ListNode, k: int) -> ListNode:
        
        head = tail = cur
        res = head.next
        
        for i in range(k):
            tail = tail.next
            if tail is None:
                return None
         
        for i in range(k - 1):
            tmp = head.next
            head.next = head.next.next
            tmp.next = tail.next
            tail.next = tmp
            
        return res