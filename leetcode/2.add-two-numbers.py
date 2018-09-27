# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        cur1 = l1
        cur2 = l2
        root = ListNode(0)
        cur = root
        addOn = 0

        while (cur1 is not None or cur2 is not None or addOn > 0):
            digit1 = cur1.val if cur1 is not None else 0
            digit2 = cur2.val if cur2 is not None else 0

            number = digit1 + digit2 + addOn
            addOn = number // 10
            cur.next = ListNode(number % 10)

            if cur1:
                cur1 = cur1.next

            if cur2:
                cur2 = cur2.next

            cur = cur.next

        return root.next
