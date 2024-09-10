
from typing import List
from collections import defaultdict
import heapq

from collections import defaultdict
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        buy = [float('-inf') for i in range(n + 1)]
        sell = [0 for i in range(n + 1)]
        rest = [0 for i in range(n + 1)]

        for i in range(1, n + 1):
            p = prices[i - 1]
            buy[i] = max(buy[i - 1], rest[i - 1] - p)
            rest[i] = max(rest[i - 1], sell[i - 1])
            sell[i] = max(sell[i - 1], buy[i] + p)

        return sell[n]

s = Solution()
res = s.maxProfit([1,2,3,0,2])
print(res)