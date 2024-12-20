#  Tag: Hash Table, String, Queue, Counting
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
#   
#  Example 1:
#  
#  Input: s = "leetcode"
#  Output: 0
#  Explanation:
#  The character 'l' at index 0 is the first character that does not occur at any other index.
#  
#  Example 2:
#  
#  Input: s = "loveleetcode"
#  Output: 2
#  
#  Example 3:
#  
#  Input: s = "aabb"
#  Output: -1
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 105
#  s consists of only lowercase English letters.
#  
#  

from collections import Counter
class Solution:
    def firstUniqChar(self, s: str) -> int:
        counter = Counter(s)
        n = len(s)
        for i in range(n):
            if counter[s[i]] == 1:
                return i
        return -1

class Solution:
    def firstUniqChar(self, s: str) -> int:
        letters = 'abcdefghijklmnopqrstuvwxyz'
        index = len(s)
        
        for l in letters:
            left = s.find(l)
            right = s.rfind(l)
            if left >= 0 and left == right:
                index = min(index, left)
                
        return -1 if index == len(s) else index
        
