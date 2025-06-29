#  Tag: String, Backtracking, Greedy, Counting, Enumeration
#  Time: O(An)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/bsC1C3R6hds

#  You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.
#  A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
#  A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by concatenating seq k times.
#  
#  For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".
#  
#  Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one. If there is no such subsequence, return an empty string.
#   
#  Example 1:
#  
#  
#  Input: s = "letsleetcode", k = 2
#  Output: "let"
#  Explanation: There are two longest subsequences repeated 2 times: "let" and "ete".
#  "let" is the lexicographically largest one.
#  
#  Example 2:
#  
#  Input: s = "bb", k = 2
#  Output: "b"
#  Explanation: The longest subsequence repeated 2 times is "b".
#  
#  Example 3:
#  
#  Input: s = "ab", k = 2
#  Output: ""
#  Explanation: There is no subsequence repeated 2 times. Empty string is returned.
#  
#   
#  Constraints:
#  
#  n == s.length
#  2 <= n, k <= 2000
#  2 <= n < k * 8
#  s consists of lowercase English letters.
#  
#  

from collections import deque
class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        counter = [0] * 26
        for ch in s:
            counter[ord(ch) - ord('a')] += 1

        res = ''
        candidates = ''
        q = deque()

        for i in range(26):
            if counter[i] >= k:
                ch = chr(ord('a') + i)
                res = ch
                candidates += ch
                q.append(ch)

        while len(q) > 0:
            cur = q.popleft()
            for ch in candidates:
                tmp = cur + ch
                if self.check(tmp, s, k):
                    res = tmp
                    q.append(tmp)

        return res

    def check(self, c: str, s: str, k: int) -> bool:
        j = 0
        for i in range(len(s)):
            if j < len(c) and c[j] == s[i]:
                j += 1

            if j == len(c) and k > 1:
                k -= 1
                j = 0

        return j == len(c)

class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        n = len(s) // k
        counter = [0] * 26
        used = [0] * 26
        for ch in s:
            counter[ord(ch) - ord('a')] += 1

        self.res = ''
        self.find(s, counter, used, n, k, '')
        return self.res

    def check(self, c: str, s: str, k: int) -> bool:
        j = 0
        for i in range(len(s)):
            if j < len(c) and c[j] == s[i]:
                j += 1

            if j == len(c) and k > 1:
                k -= 1
                j = 0

        return j == len(c)

    def find(self, s: str, counter: list, used: list, n: int, k:int, ans: str):
        if len(ans) > len(self.res) and self.check(ans, s, k):
            self.res = ans
        
        if len(ans) == n:
            return

        for i in range(25, -1, -1):
            if counter[i] - used[i] >= k:
                used[i] += k
                self.find(s, counter, used, n, k, ans + chr(ord('a') + i))
                used[i] -= k