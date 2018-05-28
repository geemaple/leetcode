# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        new_head = ListNode(0)

        while(head is not None):

            tmp = head.next

            head.next = new_head.next
            new_head.next = head

            head = tmp

        return new_head.next
