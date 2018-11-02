class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        
        mirror = 0
        origin = x
        while x > 0:
            mirror = x % 10 + mirror * 10
            x = x // 10
            
        return mirror == origin