class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        table_s = {}
        table_t = {}
        for i in range(len(s)):
            
            if s[i] in table_s and table_s[s[i]] != t[i]:
                return False
            
            if t[i] in table_t and table_t[t[i]] != s[i]:
                return False

            table_s[s[i]] = t[i]
            table_t[t[i]] = s[i]

        return True