# f[i][j] = f[i - 1][j - 1] where s[i - 1] == p[j - 1] or p[j - 1] == '?'
# f[i][j] = f[i][j - 1] or f[i - 1][j] case where p[j - 1] == '*'

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        
        m = len(s)
        n = len(p)
        
        dp = [[False for i in range(n + 1)] for j in range(m + 1)]
        dp[0][0] = True # 初始化
        
        for i in range(1, n + 1):
            if p[i - 1] == '*': 
                dp[0][i] = dp[0][i - 1] # 第一行初始化
        
        for i in range(1, m + 1):
            for j in range(1, n + 1):            
                if (p[j - 1] == '?' or s[i - 1] == p[j - 1]): #条件2 + 1
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*': # 条件3
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
                
        return dp[m][n]