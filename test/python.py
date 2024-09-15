
from typing import List
from collections import defaultdict
import heapq
from collections import deque
from typing import (
    List,
)

from typing import (
    List,
)

import heapq

class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        n = len(envelopes)
        envelopes.sort()
        res = []
        for i in range(n):
            if len(res) > 0 and (res[-1][0] == envelopes[i][0] or res[-1][1] >= envelopes[i][1]):
                continue

            index = self.lower_bound(res, envelopes[i])
            if index == len(res):
                res.append(envelopes[i])
            else:
                res.insert(index, envelopes[i])

        print(res)
        return len(res)

    def lower_bound(self, ans: list, target: list) -> int:
        left = 0
        right = len(ans)

        while left < right:
            mid = (left + right) >> 1
            if target[1] > ans[mid][1]:
                left = mid + 1
            else:
                right = mid

        return left

s = Solution()
res = s.maxEnvelopes([[30,50],[12,2],[3,4],[12,15]])
print(res)