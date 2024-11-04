
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

class Solution:
    """
    @param image: a binary matrix with '0' and '1'
    @param x: the location of one of the black pixels
    @param y: the location of one of the black pixels
    @return: an integer
    """
    def min_area(self, image: List[List[str]], x: int, y: int) -> int:
        # write your code here
        n = len(image)
        m = len(image[0])

        left = 0
        right = y
        while left < right:
            mid = (left + right) // 2
            print([image[i][mid] == 1 for i in range(n)])
            import pdb; pdb.set_trace()
            if any(image[i][mid] == 1 for i in range(n)):
                right = mid
            else:
                left = mid + 1
        
        left_most = left

        left = y
        right = m - 1
        while left < right:
            mid = (left + right) // 2 + 1
            if any(image[i][mid] == 1 for i in range(n)):
                left = mid
            else:
                right = mid - 1
                
        right_most = left
        print(left_most, right_most)
        width = right_most - left_most + 1
        return width
            

s = Solution()
ts = datetime.now()

res = s.min_area(["0010","0110","0100"], 2, 2)

print(datetime.now() - ts)
print(res)
