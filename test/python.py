
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
    def lexicalOrder(self, n: int) -> List[int]:
        res = []
        cur = 1
        print(n)
        for i in range(n):
            print(cur)
            res.append(cur)
            if cur * 10 <= n:
                cur *= 10
            else:
                while cur % 10 == 9 or cur >= n:
                    cur %= 10

                cur += 1

        return res

s = Solution()
ts = datetime.now()

res = s.lexicalOrder(13)

print(datetime.now() - ts)
print(res)
