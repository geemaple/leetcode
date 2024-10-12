#  Tag: Binary Search on Answer, Binary Search
#  Time: O(NlogA)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given n pieces of wood with length `L[i]` (integer array).
#  Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length.
#  What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.
#  
#  ---
#  
#  **Example 1**
#  
#  ```plain
#  Input:
#  L = [232, 124, 456]
#  k = 7
#  Output: 114
#  Explanation: We can cut it into 7 pieces if any piece is 114 long, however we can't cut it into 7 pieces if any piece is 115 long.
#  And for the 124 logs, the excess can be discarded and not used in its entirety.
#  ```
#  
#  **Example 2**
#  
#  ```plain
#  Input:
#  L = [1, 2, 3]
#  k = 7
#  Output: 0
#  Explanation: It is obvious we can't make it.
#  ```
#  
#  The unit of length is centimeter.The length of the woods are all positive integers,you couldn't cut wood into float length.If you couldn't get >= *k* pieces, return `0`.

from typing import (
    List,
)

class Solution:
    """
    @param l: Given n pieces of wood with length L[i]
    @param k: An integer
    @return: The maximum length of the small pieces
    """
    def wood_cut(self, l: List[int], k: int) -> int:
        # write your code here
        if sum(l) < k:
            return 0
        left = 1
        right = max(l)
        while left < right:
            mid = left + (right - left) // 2 + 1
            if self.fit(l, k, mid):
                left = mid
            else:
                right = mid - 1
        
        return left

    def fit(self, l: list, k: int, length: int) -> bool:
        count = 0
        for wood in l:
            count += wood // length
        return count >= k

