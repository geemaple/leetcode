#  Tag: Hash Table, String, Sorting
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given two strings s and t, return true if t is an anagram of s, and false otherwise.
#  An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
#   
#  Example 1:
#  Input: s = "anagram", t = "nagaram"
#  Output: true
#  Example 2:
#  Input: s = "rat", t = "car"
#  Output: false
#  
#   
#  Constraints:
#  
#  1 <= s.length, t.length <= 5 * 104
#  s and t consist of lowercase English letters.
#  
#   
#  Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
#  

from collections import defaultdict
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        n = len(s)
        count = defaultdict(int)
        for i in range(n):
            count[s[i]] += 1
            count[t[i]] -= 1

        for k in count:
            if count[k] != 0:
                return False
        return True

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        return sorted(s) == sorted(t)