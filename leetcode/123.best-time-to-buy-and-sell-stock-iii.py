#  Tag: Array, Dynamic Programming
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  You are given an array prices where prices[i] is the price of a given stock on the ith day.
#  Find the maximum profit you can achieve. You may complete at most two transactions.
#  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
#   
#  Example 1:
#  
#  Input: prices = [3,3,5,0,0,3,1,4]
#  Output: 6
#  Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
#  Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
#  Example 2:
#  
#  Input: prices = [1,2,3,4,5]
#  Output: 4
#  Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
#  Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
#  
#  Example 3:
#  
#  Input: prices = [7,6,4,3,1]
#  Output: 0
#  Explanation: In this case, no transaction is done, i.e. max profit = 0.
#  
#   
#  Constraints:
#  
#  1 <= prices.length <= 105
#  0 <= prices[i] <= 105
#  
#  

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = [float('-inf')] * 3
        sell = [0] * 3
        
        for p in prices:
            for i in range(1, 3):
                buy[i] = max(buy[i], sell[i - 1] - p)
                sell[i] = max(sell[i], buy[i] + p)

        return max(sell)

class Solution(object):
    def maxProfit(self, prices: List[int]) -> int:
        # five state as follows:
        #  
        #    1st_B 1st_S 2nd_B 2nd_S
        # -----|-----|-----|-----|-----
        #   1     2     3     4     5
        # to acquire max profit, the final state = 1 or 3 or 5
        # 
        # state 1, 3, 5 (sell on i - 1 th day)
        # f[i][j] = max(
        #    f[i - 1][j], 
        #    f[i - 1][j - 1] + prices[i - 1] - prices[i - 2]
        # )
        # 
        # state 2, 4 (hold on i - 1 th day)
        # f[i][j] = max (
        #    f[i - 1][j - 1],
        #    f[i - 1][j] + prices[i - 1] - prices[i - 2],
        #    f[i - 1][j - 2] + prices[i - 1] - prices[i - 2]

        if prices is None or len(prices) == 0:
            return 0

        m = len(prices)

        table = [[0 for _ in range(5 + 1)] for _ in range(m + 1)]

        # init
        for j in range(1, 5 + 1):
            table[0][j] = 0 if j == 1 else float('-inf')

        for i in range(1, m + 1):
            for j in range(1, 5 + 1):
                value = float('-inf')
                if j % 2 == 1:  # 1, 3, 5
                    value = table[i - 1][j]
                    if i - 2 >= 0 and j > 1 and table[i - 1][j - 1] != float('-inf'):
                        value = max(value, table[i - 1][j - 1] + prices[i - 1] - prices[i - 2])
                else:
                    value = table[i - 1][j - 1]
                    if i - 2 >= 0 and table[i - 1][j] != float('-inf'):
                        value = max(value, table[i - 1][j] + prices[i - 1] - prices[i - 2])

                    if i - 2 >= 0 and j > 2 and table[i - 1][j - 2] != float('-inf'):
                        value = max(value, table[i - 1][j - 2] + prices[i - 1] - prices[i - 2])

                table[i][j] = value

        res = 0
        for j in range(1, 5 + 1, 2):
            res = max(res, table[m][j])

        return res