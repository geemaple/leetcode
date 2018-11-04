class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(s) == 0:
            return ""
        
        longest = s[0]
        
        for t in range(len(s)):
            i = t - 1
            j = t + 1
            while (i >= 0 and j < len(s) and s[i] == s[j]):
                length = j - i + 1
                if length > len(longest):
                    longest = s[i : j + 1]
                
                i -= 1
                j += 1
                    
            i = t - 1
            j = t
            
            while (i >= 0 and j < len(s) and s[i] == s[j]):
                length = j - i + 1
                if length > len(longest):
                    longest = s[i : j + 1]
                i -= 1
                j += 1
                
        return longest