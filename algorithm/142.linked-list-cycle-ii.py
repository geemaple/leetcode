# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        quick = head
        slow = head
        result = False

        while (quick is not None and quick.next is not None):
            quick = quick.next.next
            slow = slow.next
            if quick == slow:
                result = True
                break

        if not result:
            return None

        quick = head
        while (quick != slow):
            quick = quick.next
            slow = slow.next

        return quick
