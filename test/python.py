
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
    @param n: An integer
    @return: A boolean which equals to true if the first player will win
    """
    def first_will_win(self, n: int) -> bool:
        # write your code here
        if n == 0:
            return False
            
        if n <= 2:
            return True

        dp = [False for i in range(1 + n)]
        dp[1] = dp[2] = True

        for i in range(3, n + 1):
            dp[i] = not (dp[i - 1] or dp[i - 2]) 

        return dp[n]



s = Solution()
res = s.first_will_win(0)
print(res)

res = s.first_will_win(11)
print(res)
