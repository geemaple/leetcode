#
# [24] Swap Nodes in Pairs
#
# https://leetcode.com/problems/swap-nodes-in-pairs/description/
#
# algorithms
# Medium (41.40%)
# Total Accepted:    411.3K
# Total Submissions: 851.8K
# Testcase Example:  '[1,2,3,4]'
#
# Given a linked list, swap every two adjacent nodes and return its head.
# 
# You may not modify the values in the list's nodes, only nodes itself may be
# changed.
# 
# 
# 
# Example:
# 
# 
# Given 1->2->3->4, you should return the list as 2->1->4->3.
# 
# 
#
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        newHead = ListNode(0)
        newHead.next = head
        cur = newHead

        while cur.next and cur.next.next:
            tmp = cur.next.next

            cur.next.next = tmp.next
            tmp.next = cur.next
            cur.next = tmp

            cur = cur.next.next

        return newHead.next