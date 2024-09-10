#  Tag: Array, Dynamic Programming
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given an array prices where prices[i] is the price of a given stock on the ith day.
#  Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:
#  
#  After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
#  
#  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
#   
#  Example 1:
#  
#  Input: prices = [1,2,3,0,2]
#  Output: 3
#  Explanation: transactions = [buy, sell, cooldown, buy, sell]
#  
#  Example 2:
#  
#  Input: prices = [1]
#  Output: 0
#  
#   
#  Constraints:
#  
#  1 <= prices.length <= 5000
#  0 <= prices[i] <= 1000
#  
#  

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        buy = [float('-inf') for i in range(n + 1)]
        sell = [0 for i in range(n + 1)]
        rest = [0 for i in range(n + 1)]

        for i in range(1, n + 1):
            p = prices[i - 1]
            buy[i] = max(buy[i - 1], rest[i - 1] - p)
            rest[i] = sell[i - 1]
            sell[i] = max(sell[i - 1], buy[i] + p)

        return sell[n]
    
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        buy = float('-inf')
        sell = 0
        rest = 0

        for p in prices:
            buy = max(buy, rest - p)
            rest = sell
            sell = max(sell, buy + p)

        return sell