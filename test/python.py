
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)

class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + nums + [1]
        n = len(nums)

        dp = [[0] * n for i in range(n)]

        for l in range(1, n - 1):
            for i in range(1, n - l):
                j = i + l - 1
                for k in range(i, j + 1):
                    dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k] * nums[i - 1] * nums[j + 1])

        return dp[1][n - 2]

s = Solution()
ts = datetime.now()
res = s.maxCoins([3,1,5,8])
print(datetime.now() - ts)
print(res)
