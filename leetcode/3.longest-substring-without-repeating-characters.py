#  Tag: Hash Table, String, Sliding Window
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a string s, find the length of the longest substring without repeating characters.
#   
#  Example 1:
#  
#  Input: s = "abcabcbb"
#  Output: 3
#  Explanation: The answer is "abc", with the length of 3.
#  
#  Example 2:
#  
#  Input: s = "bbbbb"
#  Output: 1
#  Explanation: The answer is "b", with the length of 1.
#  
#  Example 3:
#  
#  Input: s = "pwwkew"
#  Output: 3
#  Explanation: The answer is "wke", with the length of 3.
#  Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
#  
#   
#  Constraints:
#  
#  0 <= s.length <= 5 * 104
#  s consists of English letters, digits, symbols and spaces.
#  
#  

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        cache = set()
        res = 0
        j = 0

        for i in range(n):
            while s[i] in cache:
                cache.remove(s[j])
                j += 1

            res = max(res, i - j + 1)
            cache.add(s[i])

        return res

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        cache = {}
        res = 0
        j = 0

        for i in range(n):
            if s[i] in cache:
                j = max(j, cache[s[i]] + 1)

            res = max(res, i - j + 1)
            cache[s[i]] = i 

        return res

