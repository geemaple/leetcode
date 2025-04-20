#  Tag: Hash Table, String, Sliding Window
#  Time: O(N)
#  Space: O(K)
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
        k = len(p)
        counter = Counter(p)
        hit = 0
        res = []
        for i in range(n):
            if i >= k:
                if s[i - k] in counter:
                    counter[s[i - k]] += 1
                    if counter[s[i - k]] >= 1:
                        hit -= 1

            if s[i] in counter:
                counter[s[i]] -= 1
                if counter[s[i]] >= 0:
                    hit += 1

            if i >= k - 1:
                if hit == k:
                    res.append(i - k + 1)

        return res

from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n = len(s)
        k = len(p)
        counter = Counter(p)
        count = 0
        res = []
        for i in range(n):
            if s[i] in counter:
                counter[s[i]] -= 1
                if counter[s[i]] >= 0:
                    count += 1

            if i >= k - 1:
                if count == k:
                    res.append(i - k + 1)

                left = s[i - k + 1]
                if left in counter:
                    counter[left] += 1
                    if counter[left] >= 1:
                        count -= 1

        return res