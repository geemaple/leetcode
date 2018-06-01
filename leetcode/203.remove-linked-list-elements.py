# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        new_head = ListNode(0)
        new_head.next = head

        cur = new_head
        while(cur.next is not None):
            node = cur.next
            if node.val != val:
                cur = cur.next
                continue

            cur.next = node.next
            del node

        return new_head.next