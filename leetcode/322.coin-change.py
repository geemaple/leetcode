class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        table = [float('inf')] * (amount + 1)
        table[0] = 0

        for i in range(1, amount + 1):

            value = float('inf')
            for j in range(len(coins)):
                pre = i - coins[j]
                if pre >= 0 and table[pre] + 1 < value:
                    value = table[pre] + 1

            table[i] = value

        return -1 if table[amount] == float('inf') else table[amount]
