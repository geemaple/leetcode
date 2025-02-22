#  Tag: Same Direction Two Pointers, Greedy, Two Pointers
#  Time: O(N)
#  Space: O(N)
#  Ref: Leetcode-683
#  Note: -

#  There is a garden with `N` slots.
#  In each slot, there is a flower.
#  The `N` flowers will bloom one by one in `N` days.
#  In each day, there will be `exactly` one flower blooming and it will be in the status of blooming since then.
#  
#  Given an array `flowers` consists of number from `1` to `N`.
#  Each number in the array represents the place where the flower will open in that day.
#  
#  For example, `flowers[i] = x` means that the unique flower that blooms at day `i` will be at position `x`, where `i` and `x` will be in the range from `1` to `N`.
#  
#  Also given an integer `k`, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is `k` and these flowers are not blooming.
#  
#  If there are multiple answers, choose the smallest.
#  If there isn't such day, output -1.
#  
#  **Example 1:**
#  ```
#  Input：[1,2,3,4]，k=1
#  Output：-1
#  Explanation：The first two flowers to open are next to each other.
#  ```
#  **Example 2:**
#  ```
#  Input：[1,3,2]，k=1
#  Output：2
#  Explanation：In the second day, the first and the third flower have become blooming.
#  ```
#  
#  * The given array will be in the range `[1, 20000]`.

from typing import (
    List,
)

class Solution:
    """
    @param flowers: the place where the flower will open in that day
    @param k:  an integer
    @return: in which day meet the requirements
    """
    def k_empty_slots(self, flowers: List[int], k: int) -> int:
        # Write your code here
        n = len(flowers)
        bloom = [0 for i in range(n)]

        for i in range(n):
            bloom[flowers[i] - 1] = i + 1

        left = 0
        right = left + k + 1

        i = 0
        res = float('inf')
        while i < n and right < n:
            if i == right:
                res = min(res, max(bloom[left], bloom[right]))

            if bloom[i] < bloom[left] or bloom[i] < bloom[right]:
                left = i
                right = left + k + 1
            
            i += 1

        return res if res < float('inf') else -1

import bisect
class Solution:
    """
    @param flowers: the place where the flower will open in that day
    @param k:  an integer
    @return: in which day meet the requirements
    """
    def k_empty_slots(self, flowers: List[int], k: int) -> int:
        # Write your code here
        n = len(flowers)
        bloom = []
        for i in range(n):
            pos = bisect.bisect_left(bloom, flowers[i])
            bloom.insert(pos, flowers[i])

            if pos > 0 and flowers[i] - bloom[pos - 1] == k + 1:
                return i + 1

            if pos + 1 < len(bloom) and bloom[pos + 1] - flowers[i] == k + 1:
                return i + 1

        return -1

