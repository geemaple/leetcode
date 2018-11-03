max_integer = 2 ** 31 - 1
min_integer = - 2 ** 31
class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        
        if x == 0:
            return 0
        
        sign = 1 if x > 0 else -1
        x = abs(x)
        res = 0
        
        while x > 0:
            res = res * 10 + x % 10
            x = x // 10
            
            test = res * sign
            if test < min_integer or test > max_integer:
                return 0
            
        return res * sign