#
# @lc app=leetcode id=322 lang=python3
#
# [322] Coin Change
#
# https://leetcode.com/problems/coin-change/description/
#
# algorithms
# Medium (27.95%)
# Total Accepted:    261.6K
# Total Submissions: 810K
# Testcase Example:  '[1,2,5]\n11'
#
# You are given coins of different denominations and a total amount of money
# amount. Write a function to compute the fewest number of coins that you need
# to make up that amount. If that amount of money cannot be made up by any
# combination of the coins, return -1.
# 
# Example 1:
# 
# 
# Input: coins = [1, 2, 5], amount = 11
# Output: 3 
# Explanation: 11 = 5 + 5 + 1
# 
# Example 2:
# 
# 
# Input: coins = [2], amount = 3
# Output: -1
# 
# 
# Note:
# You may assume that you have an infinite number of each kind of coin.
# 
#
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        table = [float('inf') for _ in range(amount + 1)]
        table[0] = 0

        for i in range(1, amount + 1):

            for coin in coins:
                if i - coin >= 0 and table[i - coin] + 1 < table[i]:
                    table[i] = table[i - coin] + 1

        return table[amount] if table[amount] < float('inf') else -1


class Solution2(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        table = [float('inf') for _ in range(amount + 1)]
        table[0] = 0
        t = [0 for _ in range(amount + 1)]

        for i in range(1, amount + 1):

            for coin in coins:
                if i - coin >= 0 and table[i - coin] + 1 < table[i]:
                    table[i] = table[i - coin] + 1
                    t[i] = coin

        k = amount
        print('combinations', end=' ')
        while (t[k] > 0):
            print(t[k], end=' ')
            k = k - t[k]

        return table[amount] if table[amount] < float('inf') else -1

if __name__ == "__main__":
    s = Solution2()
    print(s.coinChange([2, 5, 7], 27))
