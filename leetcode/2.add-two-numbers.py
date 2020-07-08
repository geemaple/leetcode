#
# @lc app=leetcode id=2 lang=python3
#
# [2] Add Two Numbers
#
# https://leetcode.com/problems/add-two-numbers/description/
#
# algorithms
# Medium (33.44%)
# Total Accepted:    1.4M
# Total Submissions: 4.2M
# Testcase Example:  '[2,4,3]\n[5,6,4]'
#
# You are given two non-empty linked lists representing two non-negative
# integers. The digits are stored in reverse order and each of their nodes
# contain a single digit. Add the two numbers and return it as a linked list.
# 
# You may assume the two numbers do not contain any leading zero, except the
# number 0 itself.
# 
# Example:
# 
# 
# Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
# Output: 7 -> 0 -> 8
# Explanation: 342 + 465 = 807.
# 
# 
#
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        pre = head = ListNode()
        addition = 0
        
        while (l1 is not None or l2 is not None or addition > 0):
            num1 = 0 if l1 is None else l1.val
            num2 = 0 if l2 is None else l2.val
            
            total = num1 + num2 + addition
            addition = total // 10
            pre.next = ListNode(val = total % 10)
            
            pre = pre.next
            l1 = None if l1 is None else l1.next
            l2 = None if l2 is None else l2.next
            
        return head.next
