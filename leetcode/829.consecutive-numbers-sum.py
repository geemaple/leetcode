import math
class Solution(object):
    def consecutiveNumbersSum(self, N):
        """
        :type N: int
        :rtype: int
        """
        
        res = 1
        limit = int(math.sqrt(2 * N))
        for k in range(2, limit):
            if (N - k * (k - 1) / 2) % k == 0:
                res += 1
        return res