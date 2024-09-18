
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)

class Solution:
    def isScramble(self, s1: str, s2: str) -> bool:
        n = len(s1)
        dp = [[[False] * (n + 1) for j in range(n)] for i in range(n)]

        for l in range(1, n + 1):
            for i in range(n - l + 1):
                for j in range(n - l + 1):
                    if l == 1:
                        dp[i][j][l] = (s1[i] == s2[j])
                    else:
                        for k in range(1, l):
                            if dp[i][j][k] and dp[i + k][j + k][l - k]:
                                dp[i][j][l] = True


                            if dp[i][j + l - k][k] and dp[i + k][j][l - k]:
                                dp[i][j][l] = True

        return dp[0][0][n]

s = Solution()
ts = datetime.now()
res = s.isScramble("eebaacbcbcadaaedceaaacadccd", "eadcaacabaddaceacbceaabeccd")
print(datetime.now() - ts)
print(res)
