
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
    def intToRoman(self, num: int) -> str:
        romans = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        numbers = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        res = ''

        i = 0
        while i < len(numbers):
            if num >= numbers[i]:
                res += romans[i]
                num -= numbers[i]
            else:
                i += 1

        return res


s = Solution()
ts = datetime.now()

res = s.intToRoman(3749)

print(datetime.now() - ts)
print(res)
