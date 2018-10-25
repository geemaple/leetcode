# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        newHead = ListNode(0)
        newHead.next = head
        
        count = 0
        fast = newHead
        slow = newHead
        
        while (fast):
            fast = fast.next
            if count > n:
                slow = slow.next
            count += 1
            
        tmp = slow.next
        slow.next = slow.next.next
        del tmp
        
        return newHead.next
            