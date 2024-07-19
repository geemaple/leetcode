#  Tag: String, Dynamic Programming
#  Time: O(MN)
#  Space: O(MN)
#  Ref: -
#  Note: -

#  Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
#  In one step, you can delete exactly one character in either string.
#   
#  Example 1:
#  
#  Input: word1 = "sea", word2 = "eat"
#  Output: 2
#  Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
#  
#  Example 2:
#  
#  Input: word1 = "leetcode", word2 = "etco"
#  Output: 4
#  
#   
#  Constraints:
#  
#  1 <= word1.length, word2.length <= 500
#  word1 and word2 consist of only lowercase English letters.
#  
#  

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)

        dp = [[0 for j in range(m + 1)] for i in range(n + 1)]
        
        for i in range(n + 1):
            for j in range(m + 1):
                if i == 0:
                    dp[0][j] = j

                elif j == 0:
                    dp[i][0] = i

                elif word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                    
                else:
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1

        return dp[n][m]

                
