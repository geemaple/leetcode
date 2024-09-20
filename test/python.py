
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
        heights = heights + [-1]
        n = len(heights)
        stack = []
        res = 0

        for i in range(n):
            while len(stack) > 0 and heights[i] < heights[stack[-1]]:
                left = 0 if len(stack) == 1 else stack[-2] + 1
                area = (i - left) * heights[stack[-1]]
                res = max(res, area)
                stack.pop()

            stack.append(i)

        return res
    
    # def largestRectangleArea(self, heights: List[int]) -> int:
    #     stack = []
    #     nums = heights[:] + [-1]
    #     res = 0
        
    #     for i in range(len(nums)):
            
    #         while(stack and nums[stack[-1]] >= nums[i]):
    #             index = stack.pop()
    #             left = stack[-1] if stack else -1
    #             width = i - left + 1 - 2
    #             res = max(res, width * heights[index])
            
    #         stack.append(i)
            
    #     return res


s = Solution()
ts = datetime.now()
res = s.largestRectangleArea([4,2,0,3,2,5])
print(datetime.now() - ts)
print(res)
