#  Tag: Two Pointers, String, Greedy
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given a string s, return true if the s can be palindrome after deleting at most one character from it.
#   
#  Example 1:
#  
#  Input: s = "aba"
#  Output: true
#  
#  Example 2:
#  
#  Input: s = "abca"
#  Output: true
#  Explanation: You could delete the character 'c'.
#  
#  Example 3:
#  
#  Input: s = "abc"
#  Output: false
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 105
#  s consists of lowercase English letters.
#  
#  

class Solution:
    def validPalindrome(self, s: str) -> bool:
        l = 0
        r = len(s) - 1

        while l < r:
            if s[l] != s[r]:
                return self.isPalindrome(s, l + 1, r) or self.isPalindrome(s, l, r - 1)
            
            l += 1
            r -= 1

        return True

    def isPalindrome(self, s: str, l: int, r:int) -> bool:
        while l < r:
            if s[l] != s[r]:
                return False

            l += 1
            r -= 1

        return True
        