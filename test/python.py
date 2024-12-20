
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


import heapq
class Solution:
    def makeStringGood(self, s: str) -> int:
        n = len(s)
        occ = [0 for i in range(26)]
        
        for x in s:
            index = ord(x) - ord('a')
            occ[index] += 1

        print(occ)
        low = min(x for x in occ if x != 0)
        high = max(occ)
        res = float('inf')
        for k in range(low, high + 1):
            op = self.helper(s, k, list(occ))
            res = min(res, op)
        return res

    def helper(self, s: str, k: int, occ: list) -> int:
        
        dp = [[float('inf'), float('inf')] for i in range(27)]
        dp[0] = [0, 0]

        for i in range(1, 27):
            if occ[i - 1] == 0 or occ[i - 1] == k:
                dp[i][0] = dp[i][1] = min(dp[i - 1])
                continue
            
            # op1
            dp[i][1] = min(dp[i - 1]) + (occ[i - 1] - k if occ[i - 1] > k else occ[i - 1])

            if occ[i - 1] < k:
                # op2
                dp[i][0] = min(dp[i - 1]) + (k - occ[i - 1])
                if i - 2 >= 0:
                    op = occ[i - 2] - k if occ[i - 2] >= k else occ[i - 2]
                    res = dp[i - 1][1] + max(k - occ[i - 1] - op, 0)
                    dp[i][0] = min(dp[i][0], res)

        print(dp, k)
        return min(dp[-1])


s = Solution()
ts = datetime.now()

res = s.makeStringGood("aaabbc")

print(datetime.now() - ts)
print(res)
