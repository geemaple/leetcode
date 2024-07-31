#  Tag: String, Dynamic Programming, Recursion
#  Time: O(MN)
#  Space: O(MN)
#  Ref: -
#  Note: -

#  Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
#  
#  '.' Matches any single character.​​​​
#  '*' Matches zero or more of the preceding element.
#  
#  The matching should cover the entire input string (not partial).
#   
#  Example 1:
#  
#  Input: s = "aa", p = "a"
#  Output: false
#  Explanation: "a" does not match the entire string "aa".
#  
#  Example 2:
#  
#  Input: s = "aa", p = "a*"
#  Output: true
#  Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
#  
#  Example 3:
#  
#  Input: s = "ab", p = ".*"
#  Output: true
#  Explanation: ".*" means "zero or more (*) of any character (.)".
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 20
#  1 <= p.length <= 20
#  s contains only lowercase English letters.
#  p contains only lowercase English letters, '.', and '*'.
#  It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.
#  
#  

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)

        dp = [[False for j in range(n + 1)] for i in range(m + 1)]
        dp[0][0] = True
        for j in range(2, n + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 2]

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s[i - 1] == p[j - 1] or p[j - 1] == '.':
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*' and j - 2 >= 0:
                    dp[i][j] = dp[i][j - 2]
                    if (s[i - 1] == p[j - 2] or p[j - 2] == '.'):
                        dp[i][j] = dp[i][j] or dp[i - 1][j]
        
        return dp[m][n]