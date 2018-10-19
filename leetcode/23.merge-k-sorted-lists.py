# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

import heapq
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        heap = []
        
        for node in lists:
            if node is not None:
                heapq.heappush(heap, (node.val, node))
        
        head = ListNode(0)
        cur = head
        
        while(len(heap) > 0):
            val, neighbor = heapq.heappop(heap)
            cur.next = neighbor
            cur = cur.next
            
            if neighbor.next is not None:
                heapq.heappush(heap, (neighbor.next.val, neighbor.next))
        
        return head.next
        