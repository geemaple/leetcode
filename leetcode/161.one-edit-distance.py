class Solution(object):
    def isOneEditDistance(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        diff = len(s) - len(t)

        if abs(diff) > 1:
            return False

        if abs(diff) == 0:
            count = 0
            for i in range(len(s)):
                if s[i] != t[i]:
                    count += 1
            
            return count == 1

        if abs(diff) == 1:
            small = t if diff > 0 else s
            large = t if diff < 0 else s

            for i in range(len(small)):
                if small[i] != large[i]:
                    return small[i:] == large[i + 1:]

        return True