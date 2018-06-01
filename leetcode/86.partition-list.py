# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        
        if head is None:
            return None

        left_head = ListNode(0)
        left_head.next = head

        right_head = ListNode(0)

        left = left_head
        right = right_head

        while head:

            if head.val < x:
                left.next = head
                left = left.next
            else:
                right.next = head
                right = right.next

            head = head.next

        right.next = None
        left.next = right_head.next

        return left_head.next
