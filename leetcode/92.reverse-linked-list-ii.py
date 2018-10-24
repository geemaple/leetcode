# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """

        new_head = ListNode(0)
        new_head.next = head

        # find node.next = target
        cur = new_head
        for _ in range(m - 1):
            cur = cur.next

        head = cur
        cur = cur.next

        # n1, n2... nk, move n2, n3... nk before n1
        # times = n - 1
        # loop time = (n - m + 1) - 1
        for _ in range(n - m):

            node = cur.next
            cur.next = cur.next.next

            node.next = head.next
            head.next = node
            

        return new_head.next
