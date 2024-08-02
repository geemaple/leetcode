#  Tag: Linked List, Divide and Conquer, Heap (Priority Queue), Merge Sort
#  Time: O(NlogK)
#  Space: O(K)
#  Ref: -
#  Note: -

#  You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
#  Merge all the linked-lists into one sorted linked-list and return it.
#   
#  Example 1:
#  
#  Input: lists = [[1,4,5],[1,3,4],[2,6]]
#  Output: [1,1,2,3,4,4,5,6]
#  Explanation: The linked-lists are:
#  [
#    1->4->5,
#    1->3->4,
#    2->6
#  ]
#  merging them into one sorted list:
#  1->1->2->3->4->4->5->6
#  
#  Example 2:
#  
#  Input: lists = []
#  Output: []
#  
#  Example 3:
#  
#  Input: lists = [[]]
#  Output: []
#  
#   
#  Constraints:
#  
#  k == lists.length
#  0 <= k <= 104
#  0 <= lists[i].length <= 500
#  -104 <= lists[i][j] <= 104
#  lists[i] is sorted in ascending order.
#  The sum of lists[i].length will not exceed 104.
#  
#  

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

def node_comparator(a, b):
    return a.val < b.val
ListNode.__lt__ = node_comparator

import heapq
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        heap = []
        for node in lists:
            if node is not None:
                heapq.heappush(heap, node)
        
        head = ListNode(0)
        cur = head
        while(len(heap) > 0):
            neighbor = heapq.heappop(heap)
            cur.next = neighbor
            cur = cur.next
            
            if neighbor.next is not None:
                heapq.heappush(heap, neighbor.next)
        
        return head.next
    
from collections import deque
class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        
        q = deque(lists)
        while len(q) > 1:
            one = q.popleft()
            other = q.popleft()
            q.append(self.merge2(one, other))

        return q[0] if len(q) > 0 else None

    def merge2(self, one: ListNode, other: ListNode) -> ListNode:

        head = ListNode(0)
        cur = head
        while one is not None and other is not None:
            if one.val <= other.val:
                cur.next = one
                one = one.next
            else:
                cur.next = other
                other = other.next

            cur = cur.next

        cur.next = one if one is not None else other
        return head.next
            

