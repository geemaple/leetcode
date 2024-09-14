
from typing import List
from collections import defaultdict
import heapq
from collections import deque
class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = [0 for i in range(n + 1)]
        dp[0] = 1

        for i in range(1, n + 1):
            print(i)
            if 1 <= int(s[i - 1]) <= 9:
                dp[i] += dp[i - 1]

            import pdb; pdb.set_trace()
            if i - 2 >= 0 and (s[i - 2] == '1' or (s[i - 2] == '2' and int(s[i - 1]) <= 6)):
                dp[i] += dp[i - 2]
                

        return dp[n]

s = Solution()
res = s.numDecodings('12')
print(res)