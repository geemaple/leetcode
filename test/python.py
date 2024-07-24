from typing import List
class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        buy = [float('-inf') for i in range(n + 1)]
        sell = [0 for i in range(n + 1)]


        for i in range(1, n + 1):
            for s in range(i):
                buy[s + 1] = max(buy[s + 1], sell[s] - prices[i - 1])
                sell[s + 1] = max(sell[s + 1], prices[i - 1] + buy[s] - fee)

        return max(sell)
    
s = Solution()
res = s.maxProfit([1,3,2,8,4,9], 2)
print(res)