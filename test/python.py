
from typing import List
from collections import defaultdict
import heapq
from collections import deque
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf') for i in range(amount + 1)]
        dp[0] = 0

        for i in range(1, amount + 1):
            for c in coins:
                if i >= c and dp[i - c] + 1 < dp[i]:
                    dp[i] = dp[i - c] + 1

        return dp[amount]

s = Solution()
res = s.coinChange([1,2,5], 11)
print(res)