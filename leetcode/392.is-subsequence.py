#  Tag: Two Pointers, String, Dynamic Programming
#  Time: -
#  Space: -
#  Ref: -
#  Note: -

#  Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
#  A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
#   
#  Example 1:
#  Input: s = "abc", t = "ahbgdc"
#  Output: true
#  Example 2:
#  Input: s = "axc", t = "ahbgdc"
#  Output: false
#  
#   
#  Constraints:
#  
#  0 <= s.length <= 100
#  0 <= t.length <= 104
#  s and t consist only of lowercase English letters.
#  
#   
#  Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k >= 109, and you want to check one by one to see if t has its subsequence. In this scenario, how would you change your code?

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        n = len(s)
        m = len(t)
        i = 0
        j = 0
        while i < n and j < m:
            if s[i] == t[j]:
                i += 1
            j += 1
            
        return i == n
    
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        n = len(s)
        m = len(t)
        dp = [0 for _ in range(m + 1)]
        
        match = 0
        for i in range(1, m + 1):
            if match < n and t[i - 1] == s[match]:
                dp[i] = dp[i - 1] + 1
                match += 1
            else:
                dp[i] = dp[i - 1]
                
        return n == dp[-1]
    
from collections import defaultdict
import bisect
def batch_is_subsequence(t: str, s_list: list[str]) -> list[bool]:
    pos = defaultdict(list)
    for i, c in enumerate(t):
        pos[c].append(i)
    
    def is_subsequence(s: str) -> bool:
        prev_index = -1
        for c in s:
            if c not in pos:
                return False
            
            i = bisect.bisect_right(pos[c], prev_index)
            if i == len(pos[c]):
                return False
            prev_index = pos[c][i]
        return True

    return [is_subsequence(s) for s in s_list]