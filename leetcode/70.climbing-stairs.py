# f[i] = f[i - 1] + f[i - 2]
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        a = 1
        b = 1
        for i in range(2, n + 1):
            a, b = b, a + b
    
        return b

# f[i] = f[i - 1] + f[i - 2]
class Solution2(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        table = [0 for _ in range(n + 1)]
        table[0] = 1
        table[1] = 1
        
        for i in range(2, n + 1):
            table[i] = table[i - 1] + table[i - 2]
        
        return table[n]