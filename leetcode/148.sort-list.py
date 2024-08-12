#  Tag: Linked List, Two Pointers, Divide and Conquer, Sorting, Merge Sort
#  Time: O(NlogN)
#  Space: O(logN)
#  Ref: -
#  Note: -

#  Given the head of a linked list, return the list after sorting it in ascending order.
#   
#  Example 1:
#  
#  
#  Input: head = [4,2,1,3]
#  Output: [1,2,3,4]
#  
#  Example 2:
#  
#  
#  Input: head = [-1,5,3,4,0]
#  Output: [-1,0,3,4,5]
#  
#  Example 3:
#  
#  Input: head = []
#  Output: []
#  
#   
#  Constraints:
#  
#  The number of nodes in the list is in the range [0, 5 * 104].
#  -105 <= Node.val <= 105
#  
#   
#  Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
#  

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        if head is None or head.next is None:
            return head

        pre = None
        slow = head
        fast = head
        while fast and fast.next:
            pre = slow
            slow = slow.next
            fast = fast.next.next

        pre.next = None
        left = self.sortList(head)
        right = self.sortList(slow)

        dummy = ListNode()
        cur = dummy
        while (left and right):
            if left.val <= right.val:
                cur.next = left
                left = left.next
            else:
                cur.next = right
                right = right.next

            cur = cur.next

        cur.next = left if left else right

        return dummy.next        