
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
    """
    @param costs: n x k cost matrix
    @return: an integer, the minimum cost to paint all houses
    """
    def min_cost_i_i(self, costs: List[List[int]]) -> int:
        # write your code here
        if len(costs) == 0:
            return 0

        n = len(costs)
        m = len(costs[0])
        dp = [[0] * m for i in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(m):
                cost = float('inf')
                for k in range(m):
                    if i == 1 or j != k:
                        cost = min(cost, dp[i - 1][k] + costs[i - 1][j])

                dp[i][j] = cost

        return min(dp[n])

s = Solution()
res = s.min_cost_i_i([[5]])
print(res)