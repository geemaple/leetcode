#  Tag: Hash Table, String
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given two strings s and t, determine if they are isomorphic.
#  Two strings s and t are isomorphic if the characters in s can be replaced to get t.
#  All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
#   
#  Example 1:
#  Input: s = "egg", t = "add"
#  Output: true
#  Example 2:
#  Input: s = "foo", t = "bar"
#  Output: false
#  Example 3:
#  Input: s = "paper", t = "title"
#  Output: true
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 5 * 104
#  t.length == s.length
#  s and t consist of any valid ascii character.
#  
#  

from collections import defaultdict
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        n = len(s)
        s_mask = defaultdict(int)
        t_mask = defaultdict(int)

        for i in range(n):
            if s_mask[s[i]] != t_mask[t[i]]:
                return False
            s_mask[s[i]] = t_mask[t[i]] = i + 1

        return True

class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        table = {}
        n = len(s)
        for i in range(n):
            if s[i] in table and table[s[i]] != t[i]:
                return False

            table[s[i]] = t[i]

        table = {}
        for i in range(n):
            if t[i] in table and table[t[i]] != s[i]:
                return False

            table[t[i]] = s[i]
        
        return True
