#  Tag: Enumerate, Simulation, String
#  Time: O(N)
#  Space: O(1)
#  Ref: Leetcode-161
#  Note: -

#  Given two strings S and T, determine if they are both one edit distance apart.
#  One edit distance means doing one of these operation:
#  - insert one character in any position of S
#  - delete one character in S
#  - change any one character in S to other character
#  
#  Example 1:
#  ```
#  Input: s = "aDb", t = "adb" 
#  Output: true
#  ```
#  Example 2:
#  ```
#  Input: s = "ab", t = "ab" 
#  Output: false
#  Explanation:
#  s=t ,so they aren't one edit distance apart
#  ```
#  
#  

class Solution(object):
    def isOneEditDistance(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

        if len(s) - len(t) == 0:
            diff = 0
            for i in range(len(s)):
                if s[i] != t[i]:
                    diff += 1
                    if diff > 1:
                        break
            
            return diff == 1

        if abs(len(s) - len(t)) == 1:
            small = t if len(s) > len(t) else s
            large = t if len(s) < len(t) else s

            diff = 0
            for i in range(len(large)):
                if i - diff >= len(small) or small[i - diff] != large[i]:
                    diff += 1
                    if diff > 1:
                        break
                        
            return diff == 1
        
        return False
    
class Solution:
    """
    @param s: a string
    @param t: a string
    @return: true if they are both one edit distance apart or false
    """
    def is_one_edit_distance(self, s: str, t: str) -> bool:
        # write your code here
        n = len(s)
        m = len(t)

        if abs(n - m) > 1:
            return False

        if n > m:
            return self.is_one_edit_distance(t, s)

        for i in range(n):
            if s[i] != t[i]:
                if n == m:
                    return s[i + 1:] == t[i + 1:]
                return s[i:] == t[i + 1:]

        return n + 1 == m