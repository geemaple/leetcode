# Faster one
class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        letters = 'abcdefghijklmnopqrstuvwxyz'
        index = len(s)
        
        for l in letters:
            left = s.find(l)
            right = s.rfind(l)
            if left >= 0 and left == right:
                index = min(index, left)
                
        return -1 if index == len(s) else index

class Solution2(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        couting = {}
        for c in s:
            couting[c] = couting.get(c, 0) + 1

        for i in xrange(len(s)):
            if couting[s[i]] == 1:
                return i

        return -1