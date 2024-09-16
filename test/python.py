
from typing import List
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)

class Solution:
    """
    @param nums: an integer array and all positive numbers, no duplicates
    @param target: An integer
    @return: An integer
    """
    def back_pack_i_v(self, nums: List[int], target: int) -> int:
        # write your code here
        n = len(nums)
        dp = [[0] * (target + 1) for i in range(n + 1)]

        for i in range(n + 1):
            dp[i][0] = 1

        for i in range(1, n + 1):
            for j in range(1, target + 1):
                dp[i][j] = dp[i - 1][j]
                weight = nums[i - 1]
                if j >= weight:
                    dp[i][j] += dp[i][j - weight]

        return dp[n][target]


s = Solution()
res = s.back_pack_i_v([2,3,4,5], 7)
print(res)
