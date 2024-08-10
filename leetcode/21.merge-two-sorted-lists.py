#  Tag: Linked List, Recursion
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  You are given the heads of two sorted linked lists list1 and list2.
#  Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
#  Return the head of the merged linked list.
#   
#  Example 1:
#  
#  
#  Input: list1 = [1,2,4], list2 = [1,3,4]
#  Output: [1,1,2,3,4,4]
#  
#  Example 2:
#  
#  Input: list1 = [], list2 = []
#  Output: []
#  
#  Example 3:
#  
#  Input: list1 = [], list2 = [0]
#  Output: [0]
#  
#   
#  Constraints:
#  
#  The number of nodes in both lists is in the range [0, 50].
#  -100 <= Node.val <= 100
#  Both list1 and list2 are sorted in non-decreasing order.
#  
#  

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        head = dummy
        cur1 = list1
        cur2 = list2

        while cur1 and cur2:
            if cur1.val <= cur2.val:
                head.next = cur1
                cur1 = cur1.next
            else:
                head.next = cur2
                cur2 = cur2.next

            head = head.next

        head.next = cur1 if cur1 is not None else cur2
        return dummy.next
    
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        if list1 is None:
            return list2

        if list2 is None:
            return list1

        if list1.val <= list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2