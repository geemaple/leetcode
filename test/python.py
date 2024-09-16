
from typing import List
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)

class Solution:
    """
    @param pages: an array of integers
    @param k: An integer
    @return: an integer
    """
    def copy_books(self, pages: List[int], k: int) -> int:
        # write your code here
        n = len(pages)
        dp = [[float('inf')] * (n + 1) for i in range(k + 1)]

        for i in range(k + 1):
            dp[i][0] = 0

        for i in range(1, k + 1):
            for j in range(1, n + 1):
                work_load = 0
                for p in range(j - 1, -1, -1):
                    work_load += pages[p]
                    cost = max(dp[i - 1][p], work_load)
                    dp[i][j] = min(dp[i][j], cost)

        return dp[k][n]



s = Solution()
res = s.copy_books([3, 2, 4], 2)
print(res)