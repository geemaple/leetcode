class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
    
        if s is None or t is None or len(s) != len(t):
            return False

        left_to_right = {}
        right_to_left = {}

        for i in range(len(s)):
            if s[i] not in left_to_right:
                left_to_right[s[i]] = t[i]
            elif left_to_right[s[i]] != t[i]:
                return False

            if t[i] not in right_to_left:
                right_to_left[t[i]] = s[i]
            elif right_to_left[t[i]] != s[i]:
                return False
        
        return True
