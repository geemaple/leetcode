#
# @lc app=leetcode id=3 lang=python3
#
# [3] Longest Substring Without Repeating Characters
#
# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
#
# algorithms
# Medium (30.10%)
# Total Accepted:    1.6M
# Total Submissions: 5.2M
# Testcase Example:  '"abcabcbb"'
#
# Given a string, find the length of the longest substring without repeating
# characters.
# 
# 
# Example 1:
# 
# 
# Input: "abcabcbb"
# Output: 3 
# Explanation: The answer is "abc", with the length of 3. 
# 
# 
# 
# Example 2:
# 
# 
# Input: "bbbbb"
# Output: 1
# Explanation: The answer is "b", with the length of 1.
# 
# 
# 
# Example 3:
# 
# 
# Input: "pwwkew"
# Output: 3
# Explanation: The answer is "wke", with the length of 3. 
# ⁠            Note that the answer must be a substring, "pwke" is a
# subsequence and not a substring.
# 
# 
# 
# 
# 
#
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        left = 0
        visited = set()
        res = 0
        
        for i in range(len(s)):

            while (s[i] in visited):
                visited.remove(s[left])
                left +=1
                
            visited.add(s[i])
            
            if i - left + 1 > res:
                res = i - left + 1
                
        return res

class Solution2:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        left = 0
        visited = dict()
        res = 0
        
        for i in range(len(s)):
            if (s[i] in visited):
                left = max(left, visited[s[i]] + 1)
                
            visited[s[i]] = i
            
            if i - left + 1 > res:
                res = i - left + 1
                
        return res