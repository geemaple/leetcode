
from typing import List
from datetime import datetime
from collections import defaultdict
import heapq
from collections import deque
import math
from typing import (
    List,
)


from collections import defaultdict
class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        
        n = len(nums)
        res = []
        counter = defaultdict(int)
        for i in range(n):
            counter[nums[i]] += 1
            if i >= k - 1:
                keys = sorted(counter.keys(), key=lambda v: (-counter[v], -v))
                ans = 0
                for j in range(x):
                    v = keys[j]
                    ans += counter[v] * v
                
                res.append(ans)
                counter[nums[i - k + 1]] -= 1

        return res

s = Solution()
ts = datetime.now()
res = s.findXSum([1,1,2,2,3,4,2,3], 6, 2)
print(datetime.now() - ts)
print(res)
