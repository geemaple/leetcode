
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


# from collections import Counter
# from math import comb
# from functools import cache
# class Solution:
#     def countBalancedPermutations(self, num: str) -> int:
#         n = len(num)
#         total = sum(int(x) for x in num)
#         if total % 2 == 1:
#             return 0

#         counter = Counter(int(x) for x in num)

#         @cache
#         def dfs(digit: int, odd: int, even: int, balance: int) -> int:
#             if odd == 0 and even == 0 and balance == 0:
#                 return 1
            
#             if digit < 0 or odd < 0 or even < 0 or balance < 0:
#                 return 0

#             count = counter[digit]
#             res= 0
#             for k in range(count + 1):
#                 res += comb(odd, k) * comb(even, count - k) * dfs(digit - 1, odd - k, even - (count - k), balance - k * digit)

#             return res % 1000000007

#         return dfs(9, n - n // 2, n // 2, total // 2)

from collections import Counter
from math import comb

class Solution:
    def countBalancedPermutations(self, num: str) -> int:
        mod = 1000000007
        n = len(num)
        total_sum = sum(int(x) for x in num)

        if total_sum % 2 == 1:
            return 0

        counter = Counter(int(x) for x in num)
        even = n // 2
        balance = total_sum // 2

        dp = [[0] * (balance + 1) for i in range(even + 1)]
        dp[0][0] = 1
        
        total = 0
        for digit in counter:
            prev = [list(x) for x in dp]
            dp = [[0] * (balance + 1) for i in range(even + 1)]
            count = counter[digit]
            total += count

            for b in range(balance + 1):
                for e in range(even + 1):
                    if prev[e][b] == 0:
                        continue

                    for k in range(count + 1):
                        if e + k > even or b + k * digit > balance:
                            break
                        
                        dp[e + k][b + digit * k] += (comb(k + e, k) % mod) * (comb(total - k - e, count - k) % mod) * prev[e][b]

        return dp[even][balance] % mod
                



s = Solution()
ts = datetime.now()

res = s.countBalancedPermutations("15338359781342159844683188511637883821754570632088685")

print(datetime.now() - ts)
print(res)
