# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):

    def reverseList(self, head):
        cur = head.next
        head.next = None

        while (cur is not None):
            next = cur.next
            cur.next = head.next
            head.next = cur
            cur = next


    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        newHead = ListNode(0)
        newHead.next = head

        slow = newHead
        fast = newHead
        
        # find middle
        while (fast is not None and fast.next is not None):
            slow = slow.next
            fast = fast.next.next

        # reverse later half
        self.reverseList(slow)

        left = head
        right = slow.next
        result = True
        
        while (left is not None and right is not None):
            if left.val != right.val:
                result = False
                break

            left = left.next
            right = right.next

        # reverse it back
        # self.reverseList(slow)

        return result 