
import math
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for i in range(n)]

        start = 0
        length = 0
        for i in range(n):
            dp[i][i] = True

        for i in range(1, n):
            if s[i] == s[i - 1]:
                dp[i - 1][i] = True
                start = i - 1
                length = 2

        for l in range (3, n + 1):
            for i in range(n + 1 - l):
                j = i + l - 1
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    if length < j - i + 1:
                        length = j - i + 1
                        start = i

        return s[start: start + length]

s = Solution()
res = s.longestPalindrome("aacabdkacaa")
print(res)