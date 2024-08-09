class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        n = len(haystack)
        m = len(needle)
        
        dp = self.buildPMT(needle)
        self.buildPMT1(needle)
        count = 0

        for i in range(n):
            while count > 0 and haystack[i] != needle[count]:
                count = dp[count - 1]

            if haystack[i] == needle[count]:
                count += 1

            if count == m:
                return i - count + 1

        return -1

    def buildPMT(self, text: str):
        n = len(text)
        dp = [0 for i in range(n)]
        k = 0
        for i in range(1, n):
            
            while k > 0 and text[i] != text[k]:
                k = dp[k - 1]

            if text[i] == text[k]:
                k += 1
            
            dp[i] = k
        
        print(dp)
        return dp

    def buildPMT1(self, text: str):
        n = len(text)
        dp = [0 for i in range(n)]
        for i in range(1, n):
            print(f"i = {i} {text[i]}")
            k = dp[i - 1]
            while k > 0 and text[i] != text[k]:
                print(k)
                k -= 1
            
            print(k)
            if text[i] == text[k]:
                k += 1

            print(k)
            dp[i] = k
        
        print(dp)
        return dp
    
s = Solution()
s.strStr("adcadcaddcadde", "adcadde")