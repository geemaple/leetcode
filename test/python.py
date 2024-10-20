
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
    """
    @param nums: A list of integers
    @return: A list of integers includes the index of the first number and the index of the last number
    """
    def subarray_sum(self, nums: List[int]) -> List[int]:
        # write your code here
        pre = 0
        table = {pre: 0}
        for i in range(len(nums)):
            pre += nums[i]
            table
            print(pre, table)

        print(table)

        return [0, 0]




s = Solution()
ts = datetime.now()
res = s.subarray_sum([3,1,5,8])
print(datetime.now() - ts)
print(res)
