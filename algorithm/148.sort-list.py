# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """

        return self.merge_sort(head)

    def merge_sort(self, head):
        
        if head is None or head.next is None:
            return head

        #find middle
        quick = head.next
        slow = head
        while (quick is not None and quick.next is not None):
            quick = quick.next.next
            slow = slow.next

        left = head
        right = slow.next
        slow.next = None

        #sort left and right
        left_sort = self.merge_sort(left)
        right_sort = self.merge_sort(right)

        #merge tow result
        if left_sort is None:
            return right_sort

        if right_sort is None:
            return left_sort

        new_head = ListNode(0)
        cur = new_head
        
        while(left_sort is not None and right_sort is not None):
            if left_sort.val < right_sort.val:
                cur.next = left_sort
                left_sort = left_sort.next
            else:
                cur.next = right_sort
                right_sort = right_sort.next

            cur = cur.next

        if left_sort is not None:
            cur.next = left_sort

        if right_sort is not None:
            cur.next = right_sort

        return new_head.next