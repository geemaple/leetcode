#  Tag: String, Dynamic Programming
#  Time: O(N^2)
#  Space: O(N^2)
#  Ref: -
#  Note: -

#  Given a string s, partition s such that every substring of the partition is a palindrome.
#  Return the minimum cuts needed for a palindrome partitioning of s.
#   
#  Example 1:
#  
#  Input: s = "aab"
#  Output: 1
#  Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
#  
#  Example 2:
#  
#  Input: s = "a"
#  Output: 0
#  
#  Example 3:
#  
#  Input: s = "ab"
#  Output: 1
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 2000
#  s consists of lowercase English letters only.
#  
#  

class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        is_palindrome = [[False] * n for i in range(n)]
        for i in range(n):
            self.expand(s, i, i, is_palindrome)
            self.expand(s, i, i + 1, is_palindrome)

        dp = [i for i in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(i):
                if is_palindrome[j][i - 1]:
                    dp[i] = min(dp[i], dp[j] + 1)
        return dp[n] - 1

    def expand(self, s: str, left: int, right: int, is_palindrome:list):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            is_palindrome[left][right] = True
            left -= 1
            right += 1