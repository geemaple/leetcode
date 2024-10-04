#  Tag: Dynamic Programming/DP, Coordinate DP
#  Time: O(NM)
#  Space: O(NM)
#  Ref: Leetcode-265
#  Note: -

#  There are a row of `n` houses, each house can be painted with one of the `k` colors.
#  The cost of painting each house with a certain color is different.
#  You have to paint all the houses such that no two adjacent houses have the same color.
#  
#  The cost of painting each house with a certain color is represented by a `n` x `k` cost matrix.
#  For example, `costs[0][0]` is the cost of painting house `0` with color `0`; `costs[1][2]` is the cost of painting house `1` with color `2`, and so on...
#  Find the minimum cost to paint all houses.
#  
#  **Example 1**
#  
#  ```plain
#  Input:
#  costs = [[14,2,11],[11,14,5],[14,3,10]]
#  Output: 10
#  Explanation:
#  The three house use color [1,2,1] for each house. The total cost is 10.
#  ```
#  
#  **Example 2**
#  
#  ```plain
#  Input:
#  costs = [[5]]
#  Output: 5
#  Explanation:
#  There is only one color and one house.
#  ```
#  
#  All costs are positive integers.

from typing import (
    List,
)

class Solution:
    """
    @param costs: n x k cost matrix
    @return: an integer, the minimum cost to paint all houses
    """
    def min_cost_i_i(self, costs: List[List[int]]) -> int:
        # write your code here
        if len(costs) == 0:
            return 0

        n = len(costs)
        m = len(costs[0])
        dp = [[0] * m for i in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(m):
                cost = float('inf')
                for k in range(m):
                    if i == 1 or j != k:
                        cost = min(cost, dp[i - 1][k] + costs[i - 1][j])

                dp[i][j] = cost

        return min(dp[n])

class Solution:
    """
    @param costs: n x k cost matrix
    @return: an integer, the minimum cost to paint all houses
    """
    def min_cost_i_i(self, costs: List[List[int]]) -> int:
        # write your code here
        if len(costs) == 0:
            return 0

        n = len(costs)
        m = len(costs[0])
        dp = [[0] * m for i in range(n + 1)]

        for i in range(1, n + 1):
            pre_min1 = float('inf')
            pre_min2 = float('inf')

            for j in range(m):
                if dp[i - 1][j] < pre_min1:
                    pre_min2 = pre_min1
                    pre_min1 = dp[i - 1][j]
                elif dp[i - 1][j] < pre_min2:
                    pre_min2 = dp[i - 1][j]

            for j in range(m):
                pre = pre_min2 if i > 1 and dp[i - 1][j] == pre_min1 else pre_min1
                dp[i][j] = pre + costs[i - 1][j]

        return min(dp[n])