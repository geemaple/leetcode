#
# [14] Longest Common Prefix
#
# https://leetcode.com/problems/longest-common-prefix/description/
#
# algorithms
# Easy (32.11%)
# Total Accepted:    641.9K
# Total Submissions: 1.9M
# Testcase Example:  '["flower","flow","flight"]'
#
# Write a function to find the longest common prefix string amongst an array of
# strings.
# 
# If there is no common prefix, return an empty string "".
# 
# Example 1:
# 
# 
# Input: ["flower","flow","flight"]
# Output: "fl"
# 
# 
# Example 2:
# 
# 
# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.
# 
# 
# Note:
# 
# All given inputs are in lowercase letters a-z.
# 
#
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        
        if len(strs) == 0 or len(strs[0]) == 0:
            return ''
        
        res = ''
        for i in range(len(strs[0])):
            for j in range(1, len(strs)):
               if i >= len(strs[j]) or strs[j][i] != strs[0][i]:
                    return res
                
            res += strs[0][i]
            
        return res