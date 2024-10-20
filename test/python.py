
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
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        right_min = list(nums)
        for i in range(n - 2, -1, -1):
            right_min[i] = min(right_min[i + 1], nums[i])

        res = 0
        for i in range(n - 1):
            if nums[i] == nums[i + 1] or nums[i] <= right_min[i + 1]:
                continue
            
            for d in range(2, right_min[i + 1] + 1):
                if nums[i] % d == 0:
                    res += 1
                    j = i
                    while j > 0 and nums[j] == nums[j - 1]:
                        res += 1
                        j -= 1
                    break
            else:
                return -1

        return res


s = Solution()
ts = datetime.now()
res = s.minOperations([675,675,149,149,233])
print(datetime.now() - ts)
print(res)
