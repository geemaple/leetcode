class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        if n is None or n == 0:
            return 0

        if n == 1:
            return 1

        table = [0 for i in range(n)]

        table[0] = 1
        table[1] = 2

        for i in range(2, n):
            table[i] = table[i - 1] + table[i - 2]

        return table[-1]