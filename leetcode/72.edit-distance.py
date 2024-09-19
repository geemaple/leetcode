#  Tag: String, Dynamic Programming
#  Time: O(MN)
#  Space: O(MN)
#  Ref: -
#  Note: -

#  Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
#  You have the following three operations permitted on a word:
#  
#  Insert a character
#  Delete a character
#  Replace a character
#  
#   
#  Example 1:
#  
#  Input: word1 = "horse", word2 = "ros"
#  Output: 3
#  Explanation: 
#  horse -> rorse (replace 'h' with 'r')
#  rorse -> rose (remove 'r')
#  rose -> ros (remove 'e')
#  
#  Example 2:
#  
#  Input: word1 = "intention", word2 = "execution"
#  Output: 5
#  Explanation: 
#  intention -> inention (remove 't')
#  inention -> enention (replace 'i' with 'e')
#  enention -> exention (replace 'n' with 'x')
#  exention -> exection (replace 'n' with 'c')
#  exection -> execution (insert 'u')
#  
#   
#  Constraints:
#  
#  0 <= word1.length, word2.length <= 500
#  word1 and word2 consist of lowercase English letters.
#  
#  

class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        m = len(word1)
        n = len(word2)

        dp = [[float('inf') for j in range(n + 1)] for i in range(m + 1)]
        for i in range(m + 1):
            for j in range(n + 1):
                if i == 0:
                    dp[i][j] = j
                elif j == 0:
                    dp[i][j] = i
                elif word1[i - 1] == word2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1

        return dp[m][n]


class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n = len(word1)
        m = len(word2)
        cache = [[None] * m for i in range(n)]
        return self.helper(word1, word2, 0, 0, cache) # dict cache is slow than array

    def helper(self, word1: str, word2: str, i :int, j: int, cache: dict) -> int:
        if i == len(word1):
            return len(word2) - j

        if j == len(word2):
            return len(word1) - i

        if cache[i][j] is not None:
            return cache[i][j]

        if word1[i] == word2[j]:
            cache[i][j] = self.helper(word1, word2, i + 1, j + 1, cache)
        else:
            insert = self.helper(word1, word2, i, j + 1, cache) + 1
            delete = self.helper(word1, word2, i + 1, j, cache) + 1
            replace = self.helper(word1, word2, i + 1, j + 1, cache) + 1
            cache[i][j] = min(insert, delete, replace)

        return cache[i][j]