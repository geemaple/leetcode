#
# @lc app=leetcode id=242 lang=python
#
# [242] Valid Anagram
#
# https://leetcode.com/problems/valid-anagram/description/
#
# algorithms
# Easy (49.83%)
# Total Accepted:    327.6K
# Total Submissions: 632.5K
# Testcase Example:  '"anagram"\n"nagaram"'
#
# Given two strings s and t , write a function to determine if t is an anagram
# of s.
# 
# Example 1:
# 
# 
# Input: s = "anagram", t = "nagaram"
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: s = "rat", t = "car"
# Output: false
# 
# 
# Note:
# You may assume the string contains only lowercase alphabets.
# 
# Follow up:
# What if the inputs contain unicode characters? How would you adapt your
# solution to such case?
# 
#
# O(N) 24ms
from collections import Counter
class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False

        for l in set(s): # loop count <= 26
            if s.count(l) != t.count(l):
                return False

        return True

# O(NlogN) 60ms
class Solution2(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return sorted(s) == sorted(t)

# O(N) 48ms
class Solution3(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # https://hg.python.org/cpython/file/6f535c725b27/Objects/dictobject.c#l1839
        a = Counter(s)
        b = Counter(t)

        return a == b


