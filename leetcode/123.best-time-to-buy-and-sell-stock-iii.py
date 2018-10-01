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

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

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