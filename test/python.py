
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math

import heapq

from typing import (
    List,
)


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        pivot = n - k % n
        if pivot == n:
            return

        nums = nums[pivot:] + nums[:pivot]
        print(nums)


s = Solution()
ts = datetime.now()

res = s.rotate([1,2,3,4,5,6,7], 3)

print(datetime.now() - ts)
print(res)
