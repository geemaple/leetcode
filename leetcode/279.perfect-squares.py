# f(n) = min(f[n - j^2] + 1 where 1 <= j^2 <= n)
class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        table = [0 for _ in range(n + 1)]

        for i in range(1, n + 1):
            j = 1
            value = float('inf')
            while(j * j <= i):
                value = min(value, table[i - j * j] + 1)
                j += 1

            table[i] = value

        return table[-1]
        
