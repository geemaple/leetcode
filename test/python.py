from typing import List

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        m = len(s)
        n = len(p)

        dp = [[False for j in range(n + 1)] for i in range(m + 1)]
        dp[0][0] = True

        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if s[i - 1] == p[j - 1] or p[j - 1] == '.':
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    if j - 2 >= 0 and (s[i - 1] == p[j - 2] or p[j - 2] == '.'):
                        print('wow')
                        dp[i][j] = dp[i][j] or dp[i - 1][j] or dp[i - 1][j - 1]
        
        print(dp)
        return dp[m][n]


s = Solution()

res = s.isMatch('aa', 'a*')
print(res)