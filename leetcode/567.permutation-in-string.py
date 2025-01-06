#  Tag: Hash Table, Two Pointers, String, Sliding Window
#  Time: O(N+M)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
#  In other words, return true if one of s1's permutations is the substring of s2.
#   
#  Example 1:
#  
#  Input: s1 = "ab", s2 = "eidbaooo"
#  Output: true
#  Explanation: s2 contains one permutation of s1 ("ba").
#  
#  Example 2:
#  
#  Input: s1 = "ab", s2 = "eidboaoo"
#  Output: false
#  
#   
#  Constraints:
#  
#  1 <= s1.length, s2.length <= 104
#  s1 and s2 consist of lowercase English letters.
#  
#  

from collections import Counter
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        counter = Counter(s1)
        hit = 0
        j = 0
        for i in range(len(s2)):
            if s2[i] in counter:
                counter[s2[i]] -= 1
                if counter[s2[i]] >= 0:
                    hit += 1
            
            if i >= len(s1) - 1:
                if hit == len(s1):
                    return True

                if s2[j] in counter:
                    counter[s2[j]] += 1
                    if counter[s2[j]] > 0:
                        hit -= 1

                j += 1

        return False