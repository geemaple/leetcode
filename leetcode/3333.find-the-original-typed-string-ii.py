#  Tag: String, Dynamic Programming, Prefix Sum
#  Time: O(NK)
#  Space: O(NK)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/DiQH5HNtQSM

#  Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
#  You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
#  Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
#  Since the answer may be very large, return it modulo 109 + 7.
#   
#  Example 1:
#  
#  Input: word = "aabbccdd", k = 7
#  Output: 5
#  Explanation:
#  The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
#  
#  Example 2:
#  
#  Input: word = "aabbccdd", k = 8
#  Output: 1
#  Explanation:
#  The only possible string is "aabbccdd".
#  
#  Example 3:
#  
#  Input: word = "aaabbb", k = 3
#  Output: 8
#  
#   
#  Constraints:
#  
#  1 <= word.length <= 5 * 105
#  word consists only of lowercase English letters.
#  1 <= k <= 2000
#  
#  

class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        mod = 10 ** 9 + 7
        n = len(word)
        groups = []
        res = 1
        count = 1
        for i in range(1, n + 1):
            if i < n and word[i] == word[i - 1]:
                count += 1
            else:
                groups.append(count)
                res = (res * count) % mod
                count = 1
    
        m = len(groups)
        if k < m:
            return res

        dp = [[0] * k for i in range(m + 1)]
        dp[0][0] = 1
        prefix = [0] * (k + 1)
        for i in range(1, m + 1):
            for j in range(k - m):
                prefix[j + 1] = (prefix[j] + dp[i - 1][j]) % mod
                dp[i][j] = (prefix[j + 1] - prefix[max(0, j - groups[i - 1] + 1)]) % mod

        for j in range(k - m):
            res = (mod + res - dp[m][j]) % mod

        return res

class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        mod = 10 ** 9 + 7
        n = len(word)
        groups = []
        res = 1
        count = 1
        for i in range(1, n + 1):
            if i < n and word[i] == word[i - 1]:
                count += 1
            else:
                groups.append(count)
                res = (res * count) % mod
                count = 1
    
        m = len(groups)
        if k < m:
            return res

        dp = [[0] * k for i in range(m + 1)]
        dp[0][0] = 1
        for i in range(1, m + 1):
            for j in range(k - m):
                for c in range(min(groups[i - 1], j + 1)):
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - c]) % mod

        for j in range(k - m):
            res = (mod + res - dp[m][j]) % mod

        return res