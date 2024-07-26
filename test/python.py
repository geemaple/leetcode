from typing import List
class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        balloons = [1] + nums + [1]
        n = len(balloons)
        dp = [[0 for j in range(n)] for i in range(n)]

        for length in range(1, n - 1):
            for l in range(1, n - length):
                r = l + length - 1
                for k in range(l, r + 1):
                    p = balloons[l - 1] * balloons[k] + balloons[r + 1] + dp[l][k - 1] + dp[k + 1][r]
                    if p > dp[l][r]:
                        dp[l][r] = p

        print(dp)
        return dp[1][n - 2]


s = Solution()
res = s.maxCoins([3,1,5,8])
print(res)