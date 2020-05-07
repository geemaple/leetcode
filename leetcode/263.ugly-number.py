#
# @lc app=leetcode id=263 lang=python
#
# [263] Ugly Number
#
# https://leetcode.com/problems/ugly-number/description/
#
# algorithms
# Easy (41.25%)
# Total Accepted:    193.6K
# Total Submissions: 469.3K
# Testcase Example:  '6'
#
# Write a program to check whether a given number is an ugly number.
# 
# Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
# 
# Example 1:
# 
# 
# Input: 6
# Output: true
# Explanation: 6 = 2 × 3
# 
# Example 2:
# 
# 
# Input: 8
# Output: true
# Explanation: 8 = 2 × 2 × 2
# 
# 
# Example 3:
# 
# 
# Input: 14
# Output: false 
# Explanation: 14 is not ugly since it includes another prime factor 7.
# 
# 
# Note:
# 
# 
# 1 is typically treated as an ugly number.
# Input is within the 32-bit signed integer range: [−2^31,  2^31 − 1].
# 
#
class Solution(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """

        if num <= 0:
            return False

        test = num
        for n in [2,3,5]:
            while test % n == 0:
                test = test // n

        return test == 1

class Solution2(object):
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        
        if num <= 0:
            return False
        
        test = num
        while (test != 1):
            if test % 2 == 0:
                test = test // 2
            elif test % 3 == 0:
                test = test // 3
            elif test % 5 == 0:
                test = test // 5
            else:
                return False
            
        return True