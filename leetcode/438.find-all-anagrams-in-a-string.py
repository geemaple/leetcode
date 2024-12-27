#  Tag: Hash Table, String, Sliding Window
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
#  An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
#   
#  Example 1:
#  
#  Input: s = "cbaebabacd", p = "abc"
#  Output: [0,6]
#  Explanation:
#  The substring with start index = 0 is "cba", which is an anagram of "abc".
#  The substring with start index = 6 is "bac", which is an anagram of "abc".
#  
#  Example 2:
#  
#  Input: s = "abab", p = "ab"
#  Output: [0,1,2]
#  Explanation:
#  The substring with start index = 0 is "ab", which is an anagram of "ab".
#  The substring with start index = 1 is "ba", which is an anagram of "ab".
#  The substring with start index = 2 is "ab", which is an anagram of "ab".
#  
#   
#  Constraints:
#  
#  1 <= s.length, p.length <= 3 * 104
#  s and p consist of lowercase English letters.
#  
#  

from collections import Counter

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n = len(s)
        counter = Counter(p)
        left = len(p)
        res = []

        j = 0
        for i in range(n):
            if s[i] in counter:
                counter[s[i]] -= 1
                if counter[s[i]] >= 0:
                    left -= 1

            if i - j + 1 == len(p):
                if left == 0:
                    res.append(j)

                if s[j] in counter:
                    counter[s[j]] += 1
                    if counter[s[j]] > 0:
                        left += 1

                j += 1

        return res