
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

        for i in range(1, n - 1):
            dp[i][i] = nums[i] * nums[i - 1] * nums[i + 1]

        for l in range(2, n - 1):
            for i in range(1, n - l):
                j = i + l - 1
                score = 0
                for k in range(i, j + 1):
                    score = max(score, nums[k] * nums[i - 1] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j])

                dp[i][j] = score
             
        return dp[1][n - 2]



s = Solution()
ts = datetime.now()
res = s.maxCoins([3,1,5,8])
print(datetime.now() - ts)
print(res)
