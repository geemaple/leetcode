#  Tag: Hash Table, String, Divide and Conquer, Bit Manipulation, Sliding Window
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  A string s is nice if, for every letter of the alphabet that s contains, it appears both in uppercase and lowercase. For example, "abABB" is nice because 'A' and 'a' appear, and 'B' and 'b' appear. However, "abA" is not because 'b' appears, but 'B' does not.
#  Given a string s, return the longest substring of s that is nice. If there are multiple, return the substring of the earliest occurrence. If there are none, return an empty string.
#   
#  Example 1:
#  
#  Input: s = "YazaAay"
#  Output: "aAa"
#  Explanation: "aAa" is a nice string because 'A/a' is the only letter of the alphabet in s, and both 'A' and 'a' appear.
#  "aAa" is the longest nice substring.
#  
#  Example 2:
#  
#  Input: s = "Bb"
#  Output: "Bb"
#  Explanation: "Bb" is a nice string because both 'B' and 'b' appear. The whole string is a substring.
#  
#  Example 3:
#  
#  Input: s = "c"
#  Output: ""
#  Explanation: There are no nice substrings.
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 100
#  s consists of uppercase and lowercase English letters.
#  
#  

class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        if len(s) < 2:
            return ''

        n = len(s)
        alphabets = set(s)

        for i in range(n):
            if s[i].lower() in alphabets and s[i].upper() in alphabets:
                continue
            s1 = self.longestNiceSubstring(s[0: i])
            s2 = self.longestNiceSubstring(s[i + 1: n])
            return s1 if len(s1) >= len(s2) else s2

        return s
    
from collections import Counter, defaultdict
class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        res = ''
        for i in range(1, 27):
            tmp = self.longestNiceSubstringWithUnique(s, i)
            if len(tmp) > len(res):
                res = tmp

        return res

    def longestNiceSubstringWithUnique(self, s: str, k: int) -> str:
        n = len(s)
        i = 0
        counter = defaultdict(int)
        count = 0
        res = ''
        for j in range(n):
            counter[s[j]] += 1
            if counter[s[j]] == 1:
                other = s[j].upper() if s[j].islower() else s[j].lower()
                if other in counter:
                    count += 1

            while len(counter) > 2 * k:
                counter[s[i]] -= 1
                if counter[s[i]] == 0:
                    other = s[i].upper() if s[i].islower() else s[i].lower()
                    if other in counter:
                        count -= 1
                    del counter[s[i]]
                i += 1

            if count == k and j - i + 1 > len(res):
                res = s[i: j + 1]

        return res