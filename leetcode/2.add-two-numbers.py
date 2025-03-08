#  Tag: Linked List, Math, Recursion
#  Time: O(N + M)
#  Space: O(1)
#  Ref: -
#  Note: -

#  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
#  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#   
#  Example 1:
#  
#  
#  Input: l1 = [2,4,3], l2 = [5,6,4]
#  Output: [7,0,8]
#  Explanation: 342 + 465 = 807.
#  
#  Example 2:
#  
#  Input: l1 = [0], l2 = [0]
#  Output: [0]
#  
#  Example 3:
#  
#  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
#  Output: [8,9,9,9,0,0,0,1]
#  
#   
#  Constraints:
#  
#  The number of nodes in each linked list is in the range [1, 100].
#  0 <= Node.val <= 9
#  It is guaranteed that the list represents a number that does not have leading zeros.
#  
#  

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        cur1 = l1
        cur2 = l2
        extra = 0
        dummy = ListNode()
        cur = dummy
        while cur1 or cur2 or extra > 0:
            v1 = cur1.val if cur1 else 0
            v2 = cur2.val if cur2 else 0
            val = v1 + v2 + extra
            extra = val // 10
            cur.next = ListNode(val % 10)
            cur = cur.next
            cur1 = cur1.next if cur1 else None
            cur2 = cur2.next if cur2 else None

        return dummy.next