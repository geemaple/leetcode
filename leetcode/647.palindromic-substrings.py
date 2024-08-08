#  Tag: Two Pointers, String, Dynamic Programming
#  Time: O(N^2)
#  Space: O(1)
#  Ref: -
#  Note: DP Slow

#  Given a string s, return the number of palindromic substrings in it.
#  A string is a palindrome when it reads the same backward as forward.
#  A substring is a contiguous sequence of characters within the string.
#   
#  Example 1:
#  
#  Input: s = "abc"
#  Output: 3
#  Explanation: Three palindromic strings: "a", "b", "c".
#  
#  Example 2:
#  
#  Input: s = "aaa"
#  Output: 6
#  Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 1000
#  s consists of lowercase English letters.
#  
#  

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        res = 0
        for i in range(n):
            res += self.expand(s, i, i)
            res += self.expand(s, i, i + 1)

        return res

    def expand(self, s: str, left: int, right: int) -> int:
        count = 0

        while left >= 0 and right < len(s) and s[left] == s[right]:
            count += 1
            left -= 1
            right += 1

        return count

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        dp = [[False for j in range(n)] for i in range(n)]
        res = 0
        for i in range(n):
            dp[i][i] = True
            res += 1

        for i in range(1, n):
            if s[i] == s[i - 1]:
                dp[i - 1][i] = True
                res += 1

        for l in range(3, n + 1):
            for i in range(0, n + 1 - l):
                j = i + l - 1
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    res += 1

        return res