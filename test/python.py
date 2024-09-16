
from typing import List
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)

from typing import (
    List,
)

class Solution:
    """
    @param nums: an integer array and all positive numbers
    @param target: An integer
    @return: An integer
    """
    def back_pack_v(self, nums: List[int], target: int) -> int:
        # write your code here
        n = len(nums)
        dp = [0] * (target + 1)
        dp[0] = 1

        for i in range(1, n + 1):
            tmp = list(dp)
            for j in range(1, target + 1):
                weight = nums[i - 1]
                if j >= weight:
                    tmp[j] = dp[j] + dp[j - weight]

            dp = tmp
        return dp[target]



s = Solution()
res = s.back_pack_v([1,2,3,3,7], 7)
print(res)
