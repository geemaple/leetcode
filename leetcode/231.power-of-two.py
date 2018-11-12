class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        
        return n > 0 and not (n & (n - 1))

class Solution2(object):
    def isPowerOfTwo(self, n):
        """
            :type n: int
            :rtype: bool
            """
        
        return n > 0 and (2 ** 30) % n == 0

class Solution3(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        
        if n <= 0:
            return False
        
        number = n
        while number > 1:
            if number & 1 == 1:
                break

            number >>= 1
            
        return number == 1
