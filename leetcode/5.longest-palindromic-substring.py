#  Tag: Two Pointers, String, Dynamic Programming
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a string s, return the longest palindromic substring in s.
#   
#  Example 1:
#  
#  Input: s = "babad"
#  Output: "bab"
#  Explanation: "aba" is also a valid answer.
#  
#  Example 2:
#  
#  Input: s = "cbbd"
#  Output: "bb"
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 1000
#  s consist of only digits and English letters.
#  
#  

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        dp = [[False] * n for i in range(n)]

        start = 0
        length = 1
        for i in range(n):
            dp[i][i] = True

        for i in range(1, n):
            if s[i] == s[i - 1]:
                dp[i - 1][i] = True
                start = i - 1
                length = 2

        for l in range (3, n + 1):
            for i in range(n + 1 - l):
                j = i + l - 1
                if s[i] == s[j] and dp[i + 1][j - 1]:
                    dp[i][j] = True
                    if length < j - i + 1:
                        length = j - i + 1
                        start = i

        return s[start: start + length]
    
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        res = ''
        for i in range(n):
            tmp = self.expand(s, i, i)
            if len(res) < len(tmp):
                res = tmp

            tmp = self.expand(s, i, i + 1)
            if len(res) < len(tmp):
                res = tmp
        return res

    def expand(self, s: str, left: int, right: int) -> str:
        while left >= 0 and right < len(s):
            if s[left] == s[right]:
                left -= 1
                right += 1
            else:
                break

        return s[left + 1 : right]
    
class Solution:
    def longestPalindrome(self, s: str) -> str:
        t = '#' + '#'.join(s) + '#'
        n = len(t)
        p = [0] * n
        center = 0
        right_r = 0

        for i in range(n):
            mirror_j = 2 * center - i

            if i < right_r:
                p[i] = min(right_r - i, p[mirror_j])

            while (i + p[i] + 1 < n and i - p[i] - 1 >= 0 and t[i + p[i] + 1] == t[i - p[i] - 1 ]):
                p[i]+= 1

            if right_r < i + p[i]:
                right_r = i + p[i]
                center = i

        max_center = 0 
        max_r = 0
        for i in range(n):
            if p[i] > max_r:
                max_r = p[i]
                max_center = i

        start = (max_center - max_r) // 2
        return s[start: start + max_r]