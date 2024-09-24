
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)


from bisect import *
class Solution:
    def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
        left = -10**10
        right = 10**10
        while left < right:
            mid = (left + right) >> 1
            if self.count_less_equal(nums1, nums2, mid) < k:
                left = mid + 1
            else:
                right = mid

        return left

    def count_less_equal(self, nums1: list, nums2: list, target: int) -> int:
        n = len(nums1)
        m = len(nums2)
        count = 0
        for i in range(n):
            if nums1[i] > 0:
                count += bisect_right(nums2, target / nums1[i])
            elif nums1[i] < 0:
                count += m - bisect_left(nums2, target / nums1[i])
            else:
                count += m if target >= 0 else 0

        return count



s = Solution()
ts = datetime.now()
res = s.kthSmallestProduct([-4,-2,0,3], [2,4], 6)
print(datetime.now() - ts)
print(res)
