class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        if prices is None or len(prices) == 0:
            return 0

        low = prices[0]
        res = 0

        for i in range(1, len(prices)):
            res = max(res, prices[i] - low)
            low = min(low, prices[i])

        return res