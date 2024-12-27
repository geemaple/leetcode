
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
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        n = len(nums)
        max_heap = []
        min_heap = []

        for i in range(k):
            heapq.heappush(max_heap, (-nums[i], i))
        
        for _ in range(k >> 1): 
            x, i = heapq.heappop(max_heap)
            heapq.heappush(min_heap, (-x, i))

        ans = [self.get_med(max_heap, min_heap, k)]

        for i in range(k, n):
            x = nums[i]
            if x <= -max_heap[0][0]:
                heapq.heappush(max_heap, (-x, i))
                if nums[i - k] > -max_heap[0][0]:
                    self.move(max_heap, min_heap)
            else:
                heapq.heappush(min_heap, (x, i))
                if nums[i - k] <= -max_heap[0][0]:
                    self.move(min_heap, max_heap)

            while max_heap and max_heap[0][1] <= i - k: 
                heapq.heappop(max_heap)
                
            while min_heap and min_heap[0][1] <= i - k: 
                heapq.heappop(min_heap)
                

            print(max_heap, min_heap)
            print(len(max_heap), len(min_heap), len(max_heap) + len(min_heap))
            ans.append(self.get_med(max_heap, min_heap, k))
        
        return ans

    def move(self, h1, h2):
        x, i = heapq.heappop(h1)
        heapq.heappush(h2, (-x, i))
    
    def get_med(self, max_heap, min_heap, k):
        return -max_heap[0][0] * 1.0 if k & 1 else (min_heap[0][0] - max_heap[0][0]) / 2.0


s = Solution()
ts = datetime.now()

res = s.medianSlidingWindow([7,8,8,3,8,1,5,3,5,4], 3)

print(datetime.now() - ts)
print(res)
