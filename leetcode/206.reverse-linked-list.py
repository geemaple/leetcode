#  Tag: Linked List, Recursion
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given the head of a singly linked list, reverse the list, and return the reversed list.
#   
#  Example 1:
#  
#  
#  Input: head = [1,2,3,4,5]
#  Output: [5,4,3,2,1]
#  
#  Example 2:
#  
#  
#  Input: head = [1,2]
#  Output: [2,1]
#  
#  Example 3:
#  
#  Input: head = []
#  Output: []
#  
#   
#  Constraints:
#  
#  The number of nodes in the list is the range [0, 5000].
#  -5000 <= Node.val <= 5000
#  
#   
#  Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
#  

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pre = None
        cur = head
        while cur is not None:
            tmp = cur.next
            cur.next = pre
            pre = cur
            cur = tmp

        return pre


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.helper(head, None)

    def helper(self, node:ListNode, pre: ListNode) -> ListNode:
        if node is None:
            return pre

        cur = node.next
        node.next = pre
        return self.helper(cur, node)