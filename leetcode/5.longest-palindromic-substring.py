class Solution:
    def longestPalindrome(self, s: str) -> str:
        
        if len(s) < 2:
            return s
        
        start = 0
        end = 0
        
        n = len(s)
        table = [[True if i == j else False for j in range(n)] for i in range(n)]
        
        for l in range(2, n + 1): # 从长度2到n遍历
            for i in range(n - l + 1):
                j = i + l - 1
                
                if i + 1 > j - 1: # 如果子串为空
                    table[i][j] = s[i] == s[j]
                else:
                    table[i][j] = s[i] == s[j] and table[i + 1][j - 1]
''
                if table[i][j] and j - i + 1 > end - start + 1:
                    start = i
                    end = j
                        
        return s[start : end + 1]

class Solution2(object):
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

