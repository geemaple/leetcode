from typing import List
import collections
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        n = len(s)
        dp = [False for i in range(n + 1)]
        dp[0] = True
        

        for l in range(1, n + 1):
            for word in wordDict:
                print(l, s[l - len(word): l])
                if len(word) <= l and s[l - len(word): l] == word:
                    dp[l] = dp[l] or dp[l - len(word)]

 
        return dp[n]


s = Solution()
t = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
res = s.wordBreak("leetcode", ["leet","code"])
print(res)