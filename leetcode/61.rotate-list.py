# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """

        if head is None:
            return None

        new_head = ListNode(0)
        new_head.next = head
        
        total_count = self.count(head)
        step = k % total_count

        # find last k + 1 elements
        # start = start -> n1, n2..., nk
        start = head
        end = start
        count = 0
        while(head is not None):
            end = head

            if count > step:
                start = start.next
            count += 1
            head = head.next

        end.next = new_head.next
        new_head.next = start.next
        start.next = None

        return new_head.next

    def count(self, node):
        count = 0
        cur = node
        while (cur is not None):
            cur = cur.next
            count += 1

        return count