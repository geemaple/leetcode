class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        couting = {}
        for c in s:
            couting[c] = couting.get(c, 0) + 1

        for i in range(len(s)):
            if couting[s[i]] == 1:
                return i

        return -1