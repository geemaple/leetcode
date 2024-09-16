
from typing import List
from collections import defaultdict
import heapq
from collections import deque
import math
class Solution:
    def numSquares(self, n: int) -> int:
        dp = [i for i in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, int(math.sqrt(i)) + 1):
                print(i, j)

                dp[i] = min(dp[i], dp[i - j * j] + 1)
        
        return dp[n]

s = Solution()
res = s.numSquares(16)
print(res)