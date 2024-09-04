
from typing import List
from collections import defaultdict
import heapq

from collections import defaultdict
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        change = defaultdict(int)

        for b in bills:
            if b == 5:
                change[5] += 1
            if b == 10:
                if change[5] > 0:
                    change[5] -= 1
                else:
                    return False
            if b == 20:
                if change[10] > 0 and change[5] > 0:
                    change[10] -= 1
                    change[5] -= 1
                elif change[5] > 2:
                    change[5] -= 3
                else:
                    return False

        return True

s = Solution()
res = s.lemonadeChange([5,5,5,10,20])
print(res)