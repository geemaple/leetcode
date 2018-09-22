class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        mapings = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }

        res = 0
        for i in range(len(s)):
            res += mapings[s[i]]
            if (i - 1 >= 0 and mapings[s[i]] > mapings[s[i - 1]]):
                res -= mapings[s[i - 1]] * 2

        return res