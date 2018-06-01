# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        
        if head is None:
            return None
        
        new_head = ListNode(0)
        new_head.next = head

        start = new_head
        while start.next is not None:
            end = start

            for _ in range(k):
                end = end.next
                if end == None:
                    return new_head.next

            results = self.reverse(start, end)
            start.next = results[0]
            start = results[1]

        return new_head.next

    # start -> n1 -> n2 ... nk
    # start -> nk -> nk-1 ... n1
    # return nk -> nk-1 .... n1
    def reverse(self, start, end):
        
        current = start.next
        while start.next != end:
            pre = current
            current = current.next

            pre.next = current.next
            current.next = start.next
            start.next = current

            current = pre

        return [start.next, current]

