
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


from typing import (
    List,
)
import heapq

import bisect
class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        n = len(fruits)
        l = bisect.bisect_left(fruits, startPos - k, key=lambda x: x[0])
        pick = 0
        res = 0
        r = l
        while (r < n and fruits[r][0] <= startPos + k):
            pick += fruits[r][1]
            while min(startPos - 2 * fruits[l][0] + fruits[r][0], 2 * fruits[r][0] - fruits[l][0] - startPos) > k:
                pick -= fruits[l][1]
                l += 1

            res = max(res, pick)
            r += 1

        return res

s = Solution()
ts = datetime.now()

res = s.maxTotalFruits([[2,8],[6,3],[8,6]], 5, 4)

print(datetime.now() - ts)
print(res)
