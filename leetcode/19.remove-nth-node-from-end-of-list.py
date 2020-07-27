# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        sentryHead = ListNode()
        sentryHead.next = head
        
        slow = fast = sentryHead
        step = 0
        
        while(fast.next is not None):
            fast = fast.next
            if step >= n:
                slow = slow.next
        
            step += 1
        
        slow.next = slow.next.next
        return sentryHead.next
        