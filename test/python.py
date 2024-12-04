
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


import heapq
from collections import Counter
from collections import defaultdict
class Solution:
    def lengthLongestPath(self, input: str) -> int:
        lines = input.split('\n')
        res = 0
        prefixs = []
        for line in lines:
            tab = 0
            while line[tab] == '\t':
                tab += 1

            path = line[tab:]
            if '.' in path:
                pre = 0 if tab == 0 else prefixs[tab - 1]
                res = max(res, pre + len(path))
            else:
                while tab < len(prefixs):
                    prefixs.pop()
              
                pre = 0 if len(prefixs) == 0 else prefixs[-1]
                prefixs.append(pre + len(path) + 1)

        return res


s = Solution()
ts = datetime.now()

res = s.lengthLongestPath("a\n\tb\n\t\tc.txt\n\taaaa.txt")

print(datetime.now() - ts)
print(res)
