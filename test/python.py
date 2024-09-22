
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
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        
        prefix = [0 for i in range(len(nums) + 1)]
        n = len(prefix)
        for i in range(1, n):
            prefix[i] = nums[i - 1] + prefix[i - 1]

        res = float('inf')
        for i in range(n):
            x = prefix[i]
            j = self.binary_search(prefix,  x + target)
            if j != len(prefix):
                res = min(res, j - i)

        return res if res < float('inf') else 0

    def binary_search(self, array:list, target:int):
        
        left = 0
        right = len(array)
        while left < right:
            mid = (left + right) >> 1
            if array[mid] == target:
                return mid

            if array[mid] < target:
                left = mid + 1
            else:
                right = mid
        return left



s = Solution()
ts = datetime.now()
res = s.minSubArrayLen(7, [2,3,1,2,4,3])
print(datetime.now() - ts)
print(res)
