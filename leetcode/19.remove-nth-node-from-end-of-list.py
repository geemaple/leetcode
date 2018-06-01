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
        if head is None:
            return None

        new_head = ListNode(0)
        new_head.next = head


        count = 0
        current = new_head
        while(head is not None):
            count += 1
            head = head.next
            if count > n:
                current = current.next

        node = current.next
        current.next = node.next
        del node

        return new_head.next
