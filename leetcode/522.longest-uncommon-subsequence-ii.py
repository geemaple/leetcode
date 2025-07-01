#  Tag: Array, Hash Table, Two Pointers, String, Sorting
#  Time: O(N^2)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.
#  An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.
#  A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.
#  
#  For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
#  
#   
#  Example 1:
#  Input: strs = ["aba","cdc","eae"]
#  Output: 3
#  Example 2:
#  Input: strs = ["aaa","aaa","aa"]
#  Output: -1
#  
#   
#  Constraints:
#  
#  2 <= strs.length <= 50
#  1 <= strs[i].length <= 10
#  strs[i] consists of lowercase English letters.
#  
#  

from collections import Counter
class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        n = len(strs)
        counter = Counter(strs)
        strs.sort(key=lambda x: len(x))
        for i in range(n - 1, -1, -1):
            if counter[strs[i]] == 1:
                unique = True
                for j in range(i + 1, n):
                    if j + 1 < n and strs[j] == strs[j + 1]:
                        continue

                    if self.check(strs[j], strs[i]):
                        unique = False
                        break

                if unique:
                    return len(strs[i])
                
        return -1

    def check(self, s1: str, s2: str) -> int:
        n = len(s1)
        m = len(s2)
        j = 0
        for i in range(n):
            if j < m and s1[i] == s2[j]:
                j += 1

        return j == m