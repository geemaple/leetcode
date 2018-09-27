# O(N) Recursive
class Solution(object):
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

# O(N) Recursive
class Solution2(object):
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

# O(N)
class Solution3(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n < 0:
            x = 1 / x
            n = - n
        
        ans = 1

        for _ in range(n):
            ans = ans * x

        return ans