class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0:
            return 1.0
        
        postive = n > 0
        n = abs(n)

        count = 0
        res = 1

        step = 1
        tmp = x
        
        while count < n:
            if count + step > n:
                step = 1
                tmp = x
                
            res = res * tmp
            count += step
            
            step = step * 2
            tmp = tmp * tmp
            
        return res if postive else 1/res
        
# O(logN) Non Recursive
class Solution2(object):
   def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n < 0:
            x = 1 / x
            n = - n
        
        product = x
        ans = 1
        index = n
        while(index > 0):
            if index % 2 == 1:
                ans = ans * product

            product = product * product
            index //= 2

        return ans

# O(logN) Recursive
class Solution3(object):
    def recursivePow(self, x, n):
        if n == 0:
            return 1.0

        half = self.recursivePow(x, n // 2)

        if n % 2 == 0:
            return half * half
        else:
            return half * half * x

    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n < 0:
            x = 1 / x
            n = - n
        
        return self.recursivePow(x, n)