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
        
        head = ListNode(0)
        cur = head

        while l1 is not None and l2 is not None:
            if l1.val > l2.val:
                cur.next = l2
                cur = cur.next

                l2 = l2.next

            else:
                cur.next = l1
                cur = cur.next

                l1 = l1.next

        rest = l1 if l1 is not None else l2
        while (rest is not None):
            cur.next = rest
            cur = cur.next

            rest = rest.next

        return head.next