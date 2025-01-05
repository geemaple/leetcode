
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

class Solution:
    def maximumCoins(self, coins: List[List[int]], k: int) -> int:
        coins.sort()
        left = coins[0][0]
        right = coins[-1][1]
        if k >= right - left + 1:
            return self.collect_forward(coins, 0, k)

        res = 0
        for i in range(len(coins)):
            res = max(res, self.collect_forward(coins, i, k))

        for i in range(len(coins) - 1, -1, -1):
            res = max(res, self.collect_backward(coins, i, k))
            
        return res
    

    def collect_forward(self, coins:list, start: int, k: int) -> int:
        right = coins[start][0] + k - 1
        res = 0
        for i in range(start, len(coins)):
            if right >= coins[i][0]:
                d = min(right, coins[i][1]) - coins[i][0] + 1
                res += d * coins[i][2]
            else:
                break
        return res
        
    def collect_backward(self, coins:list, start: int, k: int) -> int:
        left = coins[start][1] - k + 1
        res = 0
        print(left, k)
        for i in range(start, -1, -1):
            if left <= coins[i][1]:
                d = coins[i][1] - max(left, coins[i][0]) + 1
                res += d * coins[i][2]
            else:
                
                break
        return res

s = Solution()
ts = datetime.now()

res = s.maximumCoins([[8,10,1],[1,3,2],[5,6,4]], 4)

print(datetime.now() - ts)
print(res)
