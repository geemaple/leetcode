# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """        
        newHead = ListNode(0)
        cur = head
        
        while cur is not None:
            tmp = cur
            cur = cur.next
            
            tmp.next = newHead.next
            newHead.next = tmp
            
        return newHead.next