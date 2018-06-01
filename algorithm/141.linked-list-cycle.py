# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        slow = head
        quick = head

        # if slow run in Loop, quick is faster than slow
        # if we think slow is still, quick is move 1 step a time
        while quick is not None and quick.next is not None:
            slow = slow.next
            quick = quick.next.next
            if quick == slow:
                return True

        return False
