
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
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        cur = None
        pre = None
        res = []

        for i in range(n):
            if i >= k:
                if nums[i - k] == pre:
                    pre = None
                if nums[i - k] == cur:
                    cur = pre
                    pre = None

            if cur is None or nums[i] > cur:
                pre = cur
                cur = nums[i]
                
            elif pre is None or nums[i] > pre:
                pre = nums[i]

            print(nums[i - k], nums[max(0, i - k + 1): i + 1], cur, pre)
            if i >= k - 1:
                res.append(cur)

        return res

s = Solution()
a = [["a","b","c","e"],["x","x","c","d"],["x","x","b","a"]]
ts = datetime.now()
res = s.maxSlidingWindow([9,10,9,-7,-4,-8,2,-6], 5)
print(datetime.now() - ts)
print(res)
