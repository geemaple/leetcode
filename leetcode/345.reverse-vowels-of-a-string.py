class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        vowels = set("aeiouAEIOU")
        s = list(s)
        
        i = 0
        j = len(s) - 1
        
        while i < j:
            while i < j and s[i] not in vowels:
                i += 1
                
            while i < j and s[j] not in vowels:
                j -= 1
                
            if i < j:
                s[i], s[j] = s[j], s[i]
            
                i += 1
                j -= 1
            
        return ''.join(s)