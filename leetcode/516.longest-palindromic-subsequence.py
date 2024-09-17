#  Tag: String, Dynamic Programming
#  Time: O(N^2)
#  Space: O(N^2)
#  Ref: -
#  Note: -

#  Given a string s, find the longest palindromic subsequence's length in s.
#  A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
#   
#  Example 1:
#  
#  Input: s = "bbbab"
#  Output: 4
#  Explanation: One possible longest palindromic subsequence is "bbbb".
#  
#  Example 2:
#  
#  Input: s = "cbbd"
#  Output: 2
#  Explanation: One possible longest palindromic subsequence is "bb".
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 1000
#  s consists only of lowercase English letters.
#  
#  

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for i in range(n)]

        for i in range(n):
            dp[i][i] = 1

        for i in range(n - 1):
            dp[i][i + 1] = 2 if s[i] == s[i + 1] else 1

        for l in range(3, n + 1):
            for i in range(n - l + 1):
                j = i + l - 1
                
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j])
                    
        return dp[0][n - 1]

class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        cache = [[-1] * n for i in range(n)]
        return self.helper(s, 0, n - 1, cache)

    def helper(self, s: str, i: int, j: int, cache: list) -> int:
        if i > j:
            return 0

        if i == j:
            return 1

        if cache[i][j] == -1:
            if s[i] == s[j]:
                cache[i][j] = self.helper(s, i + 1, j - 1, cache) + 2
            else:
                left = self.helper(s, i + 1, j, cache)
                right = self.helper(s, i, j - 1, cache)
                cache[i][j] = max(left, right)

        return cache[i][j]