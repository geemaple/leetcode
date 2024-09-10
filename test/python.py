
from typing import List
from collections import defaultdict
import heapq

from collections import defaultdict
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        min_pre = nums[0]
        max_pre = nums[0]
        res = nums[0]

        for i in range(1, n):
            if nums[i] >= 0:
                max_pre = max(nums[i], nums[i] * max_pre)
                min_pre = min(nums[i], nums[i] * min_pre)
            else:
                max_pre, min_pre = max(nums[i], nums[i] * min_pre), min(nums[i], nums[i] * max_pre)

            res = max(res, max_pre)

        return res

s = Solution()
res = s.maxProduct([-4,-3,-2])
print(res)