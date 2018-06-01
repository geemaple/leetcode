# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """

        if headA is None or headB is None:
            return None

        curA = headA
        curB = headB

        lastA = None
        lastB = None

        while(curA != curB):
            if curA.next is None:
                lastA = curA
                curA = headB
            else:
                curA = curA.next

            if curB.next is None:
                lastB = curB
                curB = headA
            else:
                curB = curB.next

            if lastA is not None and lastB is not None and lastA != lastB:
                return None

        return curA