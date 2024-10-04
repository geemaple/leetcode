#  Tag: Breadth-First Search, Array, Dynamic Programming
#  Time: O(K * N)
#  Space: O(N)
#  Ref: -
#  Note: Index
#  Video: https://youtu.be/EjMjlFjLRiM

#  You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
#  Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
#  You may assume that you have an infinite number of each kind of coin.
#   
#  Example 1:
#  
#  Input: coins = [1,2,5], amount = 11
#  Output: 3
#  Explanation: 11 = 5 + 5 + 1
#  
#  Example 2:
#  
#  Input: coins = [2], amount = 3
#  Output: -1
#  
#  Example 3:
#  
#  Input: coins = [1], amount = 0
#  Output: 0
#  
#   
#  Constraints:
#  
#  1 <= coins.length <= 12
#  1 <= coins[i] <= 231 - 1
#  0 <= amount <= 104
#  
#  

class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [float('inf') for _ in range(amount + 1)]
        dp[0] = 0

        for i in range(1, amount + 1):
            for c in coins:
                if i >= c:
                    dp[i] = min(dp[i], dp[i - c] + 1)

        return -1 if dp[amount] == float('inf') else dp[amount]

class Solution:

    def coinChange(self, coins: List[int], amount: int) -> int:
        self.cache = {}
        res = self.helper(coins, amount)
        return -1 if res == float('inf') else res

    def helper(self, coins: List[int], amount: int) -> int:
        if amount in self.cache:
            return self.cache[amount]

        if amount == 0:
            self.cache[amount] = 0
            return 0

        count = float('inf')
        for c in coins:
            if amount >= c:
                count = min(count, 1 + self.helper(coins, amount - c))

        self.cache[amount] = count
        return count

# backpack
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        n = len(coins)
        m = amount
        dp = [[float('inf') for j in range(m + 1)] for i in range(n + 1)]

        dp[0][0] = 0
        for i in range(1, n + 1):
            coin = coins[i - 1]
            for j in range(m + 1):
                if coin <= j:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coin] + 1)
                else:
                    dp[i][j] = dp[i - 1][j]

        return -1 if dp[n][m] == float('inf') else dp[n][m]
    
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        
        n = len(coins)
        m = amount
        dp = [float('inf') for j in range(m + 1)]

        dp[0] = 0
        for i in range(1, n + 1):
            coin = coins[i - 1]
            for j in range(coin, m + 1):
                dp[j] = min(dp[j], dp[j - coin] + 1)

        return -1 if dp[m] == float('inf') else dp[m]