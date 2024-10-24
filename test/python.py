
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
    def getSum(self, a: int, b: int) -> int:
        mask = 0xffffffff
        while ((b & mask) != 0):
            sum_without_carry = a ^ b
            carry = (a & b) << 1

            a = sum_without_carry
            b = carry
            
        if (b) > 0:
            import pdb; pdb.set_trace()

        return a


s = Solution()
ts = datetime.now()
for i in range(-1000, 1001):
    for j in range(-1000, 1001):
        print(i, j)
        res = s.getSum(i, j)


print(datetime.now() - ts)
print(res)
