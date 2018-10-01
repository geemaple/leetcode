class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if prices is None or len(prices) == 0 or k == 0:
            return 0

        res = 0
        m = len(prices)
        
        if k > m // 2: # same as stock 2
            for i in range(1, m):
                if prices[i] - prices[i - 1] > 0:
                    res += prices[i] - prices[i - 1]

        else: # same as stock 3
            state = 2 * k + 1
            table = [[0 for _ in range(state + 1)] for _ in range(m + 1)]

            # init
            for j in range(1, state + 1):
                table[0][j] = 0 if j == 1 else float('-inf')

            for i in range(1, m + 1):
                for j in range(1, state + 1):
                    value = 0
                    if j % 2 == 1: # 1, 3, 5
                        # f[i][j] = max(f[i - 1][j], f[i - 1][j - 1] + prices[i - 1] - prices[i - 2])
                        value = table[i - 1][j]

                        if i - 2 >= 0 and j > 1 and table[i - 1][j - 1] != float('-inf'):
                            value = max(value, table[i - 1][j - 1] + prices[i - 1] - prices[i - 2])

                    else: # 2, 4, 6
                        # f[i][j] = max(f[i - 1][j - 1], f[i - 1][j] + prices[i - 1] - prices[i - 2], f[i - 1][j - 2] + prices[i - 1] - prices[i - 2])
                        value = table[i - 1][j - 1]

                        if i - 2 >= 0 and table[i - 1][j] != float('-inf'):
                            value = max(value, table[i - 1][j] + prices[i - 1] - prices[i - 2])

                        if i - 2 >= 0 and j > 2 and table[i - 1][j - 2] != float('-inf'):
                            value = max(value, table[i - 1][j - 2] + prices[i - 1] - prices[i - 2])
                
                    table[i][j] = value

            for j in range(1, state + 1, 2):
                res = max(res, table[m][j])

        return res