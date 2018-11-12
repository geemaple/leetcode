class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # 3 ** 19 < MAX_INT
        # 3 ** 20 > MAX_INT
        
        return n > 0 and (3 ** 19) % n == 0