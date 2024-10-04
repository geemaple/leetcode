
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
    def solveNQueens(self, n: int) -> List[List[str]]:
        res = []
        self.helper(n, 0, 0, 0, 0, [], res)
        return res

    def helper(self, n:int, row: int, col: int, left: int, right: int, ans: list, res: list):
        if row == n:
            res.append(list(ans))
            return

        taken = col | left | right
        mask = ~taken & ((1 << n) - 1)

        while mask > 0:
            pos = mask & (-mask)

            tmp = ['Q' if 2 ** j == pos else '.' for j in range(n)]
            ans.append(tmp)
            self.helper(n, row + 1, col | pos, (left | pos) << 1, (right | pos) >> 1, ans, res)
            ans.pop()

            mask &= mask - 1


s = Solution()
ts = datetime.now()
res = s.solveNQueens(4)
print(datetime.now() - ts)
print(res)
