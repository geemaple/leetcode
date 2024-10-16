#  Tag: Dynamic Programming/DP, Game Theory, Game DP
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  There are n coins with different value in a line.
#  Two players take turns to take one or two coins from **left side** until there are no more coins left.
#  The player who take the coins with the most value wins.
#  
#  Could you please decide the **first** player will win or lose?
#  
#  If the first player wins, return `true`, otherwise return `false`.
#  
#  **Example 1:**
#  
#  ```
#  Input: [1, 2, 2]
#  Output: true
#  Explanation: The first player takes 2 coins.
#  ```
#  
#  **Example 2:**
#  
#  ```
#  Input: [1, 2, 4]
#  Output: false
#  Explanation: Whether the first player takes 1 coin or 2, the second player will gain more value.
#  ```
#  
#  

from typing import (
    List,
)

class Solution:
    """
    @param values: a vector of integers
    @return: a boolean which equals to true if the first player will win
    """
    def first_will_win(self, values: List[int]) -> bool:
        # write your code here
        n = len(values)
        dp = [0 for i in range(n + 1)]
        dp[n - 1] = values[n - 1]

        for i in range(n - 2, -1, -1):
            v = values[i]
            dp[i] = max(dp[i], v - dp[i + 1])

            v = values[i] + values[i + 1]
            dp[i] = max(dp[i], v - dp[i + 2])

        return dp[0] > 0