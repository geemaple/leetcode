class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """

        # 0x55555555 is to get rid of those power of 2 but not power of 4
        # so that the single 1 bit always appears at the odd position 
        return num > 0 and (num & (num - 1)) == 0 and (num & 0x55555555) == num
