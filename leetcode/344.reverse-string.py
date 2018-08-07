class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        # s[i] = 'char' will cause error
        # TypeError: 'unicode'/'str' object does not support item assignment
        return s[::-1]
