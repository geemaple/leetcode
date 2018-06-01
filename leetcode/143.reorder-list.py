# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: void Do not return anything, modify head in-place instead.
        """
        
        if head is None:
            return

        slow = head
        quick = head

        # find middle element
        while(quick is not None):
            quick = quick.next
            if quick is not None and quick.next is not None:
                quick = quick.next
                slow = slow.next

        right_head = ListNode(0)
        
        # reverse right part
        cur = slow.next
        slow.next = None
        while (cur is not None):
            tmp = cur.next
            cur.next = right_head.next
            right_head.next = cur
            cur = tmp

        # merge left and right
        result = ListNode(0)
        is_left = True
        left = head
        right = right_head.next
        cur = result

        while (left is not None and right is not None):
            if is_left:
                cur.next = left
                left = left.next
            else:
                cur.next = right
                right = right.next

            cur = cur.next
            is_left = not is_left

        if left is not None:
            cur.next = left

        if right is not None:
            cur.next = right

        head = result.next