
from typing import List
from collections import defaultdict
import heapq
from collections import deque
class Solution:
    def maxPossibleScore(self, start: List[int], d: int) -> int:
        n = len(start)
        start.sort()
        right = float('inf')
        for i in range(1, n):
            right = min(right, start[i] - start[i - 1])

        left = 0
        right = right + d
        while left < right:
            mid = (left + right) // 2
            if self.fit(start, d, mid):
                right = mid
            else:
                right = mid + 1

        return left

    def fit(self, start: list, d: int, ans:int) -> bool:
        pos = start[0]
        i = 1

        while i < len(start) and pos + ans <= start[i] + d:
            pos = max(start[i], pos + ans)
            i += 1
            
        return i == len(start)

s = Solution()
res = s.maxPossibleScore([6,0,3], 2)
print(res)