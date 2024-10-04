#  Tag: Dynamic Programming/DP, Coordinate DP
#  Time: O(N)
#  Space: O(N)
#  Ref: Leetcode-256
#  Note: -

#  There are a row of `n` houses, each house can be painted with one of the three colors: red, blue or green.
#  The cost of painting each house with a certain color is different.
#  You have to paint all the houses such that **no two adjacent houses have the same color,** and you need to cost the least.
#  Return the minimum cost.
#  
#  
#  The cost of painting each house with a certain color is represented by a `n` x `3` cost matrix.
#  For example, `costs[0][0]` is the cost of painting house `0` with color red; `costs[1][2]` is the cost of painting house `1` with color green, and so on...
#  Find the minimum cost to paint all houses.
#  
#  **Example 1:**
#  
#  ```
#  Input: [[14,2,11],[11,14,5],[14,3,10]]
#  Output: 10
#  Explanation: Paint house 0 into blue, paint house 1 into green, paint house 2 into blue. Minimum cost: 2 + 5 + 3 = 10.
#  ```
#  
#  **Example 2:**
#  
#  ```
#  Input: [[1,2,3],[1,4,6]]
#  Output: 3
#  ```
#  
#  All costs are positive integers.

from typing import (
    List,
)

from typing import (
    List,
)

class Solution:
    """
    @param costs: n x 3 cost matrix
    @return: An integer, the minimum cost to paint all houses
    """
    def min_cost(self, costs: List[List[int]]) -> int:
        # write your code here
        n = len(costs)
        m = 3

        dp = [[0] * 3 for i in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(m):
                dp[i][j] = min(dp[i - 1][(j + 1) % m], dp[i - 1][(j + 2) % m]) + costs[i - 1][j]

        return min(dp[n])