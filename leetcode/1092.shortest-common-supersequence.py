#  Tag: String, Dynamic Programming
#  Time: O(NM)
#  Space: O(NM)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/5fRF2U2DdEY

#  Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
#  A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
#   
#  Example 1:
#  
#  Input: str1 = "abac", str2 = "cab"
#  Output: "cabac"
#  Explanation: 
#  str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
#  str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
#  The answer provided is the shortest such string that satisfies these properties.
#  
#  Example 2:
#  
#  Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
#  Output: "aaaaaaaa"
#  
#   
#  Constraints:
#  
#  1 <= str1.length, str2.length <= 1000
#  str1 and str2 consist of lowercase English letters.
#  
#  

class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        n = len(str1)
        m = len(str2)

        dp = [[0] * (m + 1) for i in range(n + 1)]
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if str1[i - 1] == str2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

        i, j = n, m
        lcs = ['' for i in range(dp[n][m])]
        while i > 0 and j > 0 and dp[i][j] > 0:
            if str1[i - 1] == str2[j - 1]:
                lcs[dp[i][j] - 1] = str1[i - 1]
                i -= 1
                j -= 1
            elif dp[i - 1][j] > dp[i][j - 1]:
                i -= 1
            else:
                j -= 1

        res = ''
        i = 0
        j = 0
        for k in lcs:
            while str1[i] != k:
                res += str1[i]
                i += 1
            
            while str2[j] != k:
                res += str2[j]
                j += 1

            res += k
            i += 1
            j += 1

        if i < n:
            res += str1[i:]

        if j < m:
            res += str2[j:]

        return res