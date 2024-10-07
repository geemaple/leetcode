
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
    def largestRectangleArea(self, heights: List[int]) -> int:
        
        heights = [0] + heights + [0]
        stack = [0]
        n = len(heights)

        res = 0
        for i in range(1, n):
            while heights[i] < heights[stack[-1]]:
                h = heights[stack[-1]]
                stack.pop()
                width = i - stack[-1] - 1
                print(width, h, i)
                res = max(res, width * h)

            stack.append(i)

        return res
        


        

s = Solution()
a = [["a","b","c","e"],["x","x","c","d"],["x","x","b","a"]]
ts = datetime.now()
res = s.largestRectangleArea([2,1,5,6,2,3])
print(datetime.now() - ts)
print(res)
