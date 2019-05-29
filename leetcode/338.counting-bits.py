#
# @lc app=leetcode id=338 lang=python
#
# [338] Counting Bits
#
# https://leetcode.com/problems/counting-bits/description/
#
# algorithms
# Medium (63.30%)
# Total Accepted:    167.6K
# Total Submissions: 259.1K
# Testcase Example:  '2'
#
# Given a non negative integer number num. For every numbers i in the range 0 ≤
# i ≤ num calculate the number of 1's in their binary representation and return
# them as an array.
# 
# Example 1:
# 
# 
# Input: 2
# Output: [0,1,1]
# 
# Example 2:
# 
# 
# Input: 5
# Output: [0,1,1,2,1,2]
# 
# 
# Follow up:
# 
# 
# It is very easy to come up with a solution with run time
# O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
# single pass?
# Space complexity should be O(n).
# Can you do it like a boss? Do it without using any builtin function like
# __builtin_popcount in c++ or in any other language.
# 
#
class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        
        res = [0 for i in range(num + 1)]

        for i in range(1, num + 1):
            res[i] = res[i & (i - 1)] + 1

        return res

# f(x) = f(x >> 1) + x % 2
class Solution2(object):
    def countBits(self, num):
        """
            :type num: int
            :rtype: List[int]
            """
        table = []
        
        for i in range(num + 1):
            table.append(i % 2)
            pre = i >> 1
            
            if pre > 0:
                table[i] += table[pre]
    
    return table
