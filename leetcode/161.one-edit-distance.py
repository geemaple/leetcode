class Solution(object):
    def isOneEditDistance(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        if len(s) - len(t) == 0:
            diff = 0
            for i in range(len(s)):
                if s[i] != t[i]:
                    diff += 1
                    if diff > 1:
                        break
            
            return diff == 1

        if abs(len(s) - len(t)) == 1:
            small = t if len(s) > len(t) else s
            large = t if len(s) < len(t) else s

            diff = 0
            for i in range(len(large)):
                if i - diff >= len(small) or small[i - diff] != large[i]:
                    diff += 1
                    if diff > 1:
                        break
                        
            return diff == 1
        
        return False