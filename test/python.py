
from typing import List
from collections import defaultdict
import heapq

from collections import defaultdict
class Solution:
    def maxScore(self, grid: List[List[int]]) -> int:
        n = len(grid)
        m = len(grid[0])

        indexes = defaultdict(set)
        for i in range(n):
            for j in range(m):
                indexes[grid[i][j]].add(i)

        dp = [0 for i in range(1 << n)]
        for v, index in indexes.items():
            # for i in range((1 << n) - 1, 0, -1):
            for i in range(1, (1 << n)):
                for j in index:
                    if (i >> j & 1):
                        dp[i] = max(dp[i], dp[i ^ (1 << j)] + v)
                        print(f"{v} {j} dp[{bin(i)}] = {dp[i]} dp[{bin(i ^ (1 << j))}] = {dp[i ^ (1 << j)]}")
        return dp[-1]        


s = Solution()
res = s.maxScore([[8,7,6],[8,3,2]])
print(res)