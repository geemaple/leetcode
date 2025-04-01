#  Tag: Hash Table, String, Sliding Window
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a string s and an integer k, return the total number of substrings of s where at least one character appears at least k times.
#   
#  Example 1:
#  
#  Input: s = "abacb", k = 2
#  Output: 4
#  Explanation:
#  The valid substrings are:
#  
#  "aba" (character 'a' appears 2 times).
#  "abac" (character 'a' appears 2 times).
#  "abacb" (character 'a' appears 2 times).
#  "bacb" (character 'b' appears 2 times).
#  
#  
#  Example 2:
#  
#  Input: s = "abcde", k = 1
#  Output: 15
#  Explanation:
#  All substrings are valid because every character appears at least once.
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 3000
#  1 <= k <= s.length
#  s consists only of lowercase English letters.
#  
#  

from collections import defaultdict
class Solution:
    def numberOfSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        counter = defaultdict(int)
        i = 0
        res = 0
        for j in range(n):
            counter[s[j]] += 1
            while counter[s[j]] >= k:
                res += n - j
                counter[s[i]] -= 1
                i += 1
                
        return res