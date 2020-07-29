# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        cur = head = ListNode()
        
        while(l1 is not None or l2 is not None):
            
            l1_val = l1.val if l1 is not None else float('inf') 
            l2_val = l2.val if l2 is not None else float('inf') 
            
            if l1_val <= l2_val:
                cur.next = l1
                l1 = l1.next
            else:
                cur.next = l2
                l2 = l2.next
                
            cur = cur.next
            
        return head.next


