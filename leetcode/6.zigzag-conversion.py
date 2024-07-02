#
# @lc app=leetcode id=6 lang=python3
#
# [6] ZigZag Conversion
#
# https://leetcode.com/problems/zigzag-conversion/description/
#
# algorithms
# Medium (35.29%)
# Total Accepted:    460.4K
# Total Submissions: 1.3M
# Testcase Example:  '"PAYPALISHIRING"\n3'
#
# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
# of rows like this: (you may want to display this pattern in a fixed font for
# better legibility)
# 
# 
# P   A   H   N
# A P L S I I G
# Y   I   R
# 
# 
# And then read line by line: "PAHNAPLSIIGYIR"
# 
# Write the code that will take a string and make this conversion given a
# number of rows:
# 
# 
# string convert(string s, int numRows);
# 
# Example 1:
# 
# 
# Input: s = "PAYPALISHIRING", numRows = 3
# Output: "PAHNAPLSIIGYIR"
# 
# 
# Example 2:
# 
# 
# Input: s = "PAYPALISHIRING", numRows = 4
# Output: "PINALSIGYAHRPI"
# Explanation:
# 
# P     I    N
# A   L S  I G
# Y A   H R
# P     I
# 
#
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        
        if numRows < 2 or numRows >= len(s):
            return s
        
        rows = ['' for i in range(numRows)]
        
        i = 0
        while (i < len(s)):
            n = 0
            while n < numRows and i < len(s):
                # 垂直向下｜
                rows[n] += s[i]
                i += 1
                n += 1
            
            n = numRows - 2
            while n > 0 and i < len(s):
                # 斜向上 /
                rows[n] += s[i]
                i += 1
                n -= 1
                    
        return ''.join(rows)

class Solution2:
    def convert(self, s: str, numRows: int) -> str:
        
        if numRows < 2 or numRows >= len(s):
            return s
        
        base = (numRows - 1) * 2
        res = ''
        
        for i in range(numRows):
            step = i
            last = i * 2
            
            while(step < len(s)):
                res += s[step]
                if base - last > 0:
                    step += base - last
                    last = base - last
                else:
                    step += base
                    last = base
                    
        return res
