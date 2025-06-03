#  Tag: Two Pointers, String, Stack, Simulation
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
#  Note that after backspacing an empty text, the text will continue empty.
#   
#  Example 1:
#  
#  Input: s = "ab#c", t = "ad#c"
#  Output: true
#  Explanation: Both s and t become "ac".
#  
#  Example 2:
#  
#  Input: s = "ab##", t = "c#d#"
#  Output: true
#  Explanation: Both s and t become "".
#  
#  Example 3:
#  
#  Input: s = "a#c", t = "b"
#  Output: false
#  Explanation: s becomes "c" while t becomes "b".
#  
#   
#  Constraints:
#  
#  1 <= s.length, t.length <= 200
#  s and t only contain lowercase letters and '#' characters.
#  
#   
#  Follow up: Can you solve it in O(n) time and O(1) space?
#  

class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        n = len(s)
        m = len(t)
        i = n - 1
        j = m - 1
        while i >= 0 or j >= 0:
            back = 0
            while i >= 0 and (s[i] == '#' or back > 0):
                back += 1 if s[i] == '#' else -1
                i -= 1

            back = 0
            while j >= 0 and (t[j] == '#' or back > 0):
                back += 1 if t[j] == '#' else -1
                j -= 1

            if i == -1 or j == -1 or s[i] != t[j]:
                break

            i -= 1
            j -= 1

        return i == -1 and j == -1
