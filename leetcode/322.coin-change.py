class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        table = [float('inf') for i in range(amount + 1)]
        table[0] = 0
            
        for t in range(1, amount + 1):
            for c in coins:
                if t - c >= 0 and table[t - c] + 1 < table[t]:
                    table[t] = table[t - c] + 1
                    
        return table[amount] if table[amount] != float('inf') else -1