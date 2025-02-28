#  Tag: Depth First Search/DFS
#  Time: O(2^K)
#  Space: O(LogN)
#  Ref: -
#  Note: -

#  A non-negative numbers can be regarded as product of its factors.
#  Write a function that takes an integer n and return all possible combinations of its factors.
#  
#  **Example1**
#  ```
#  Input: 8
#  Output: [[2,2,2],[2,4]]
#  Explanation:
#  8 = 2 x 2 x 2 = 2 x 4
#  ```
#  **Example2**
#  ```
#  Input: 1
#  Output: []
#  ```
#  
#  - Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
#  - The solution set must not contain duplicate combination.

from typing import (
    List,
)

class Solution:
    """
    @param n: An integer
    @return: a list of combination
             we will sort your return value in output
    """
    def get_factors(self, n: int) -> List[List[int]]:
        # write your code here
        res = []
        self.helper(n, 2, [], res)
        return res

    def helper(self, n: int, start: int, ans: list, res: list):
        if len(ans) > 0:
            res.append(ans + [n])

        for k in range(start, n):
            if n // k < k:
                break

            if n % k == 0:
                self.helper(n // k, k, ans + [k], res)