# f[i] = (k - 1) * f[i - 1] + (k - 1) * f[i - 2]
class Solution(object):
    def numWays(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        
        if n == 0 or k == 0:
            return 0
        
        if n == 1:
            return k
        
        f = [0 for _ in range(n + 1)]
        f[1] = k
        f[2] = k * k
        
        for i in range(3, n + 1):
            f[i] = (k - 1) * f[i - 1] + (k - 1) * f[i - 2]
            
        return f[n]

class Solution2(object):
    def numWays(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        
        if n == 0 or k == 0:
            return 0
        
        if n == 1:
            return k
        
        same = k
        diff = k * (k - 1)
        
        for i in range(3, n + 1):
            same, diff = diff, (same + diff) * (k - 1)
            
        return same + diff