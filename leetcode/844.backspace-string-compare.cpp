//  Tag: Two Pointers, String, Stack, Simulation
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
//  Note that after backspacing an empty text, the text will continue empty.
//   
//  Example 1:
//  
//  Input: s = "ab#c", t = "ad#c"
//  Output: true
//  Explanation: Both s and t become "ac".
//  
//  Example 2:
//  
//  Input: s = "ab##", t = "c#d#"
//  Output: true
//  Explanation: Both s and t become "".
//  
//  Example 3:
//  
//  Input: s = "a#c", t = "b"
//  Output: false
//  Explanation: s becomes "c" while t becomes "b".
//  
//   
//  Constraints:
//  
//  1 <= s.length, t.length <= 200
//  s and t only contain lowercase letters and '#' characters.
//  
//   
//  Follow up: Can you solve it in O(n) time and O(1) space?
//  

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = n - 1;
        int j = m - 1;
        int back = 0;
        while (i >= 0 || j >= 0) {
            back = 0;
            while (i >= 0 && (s[i] == '#' || back > 0)) {
                back += s[i] == '#' ? 1: -1;
                i -= 1;
            }

            back = 0;
            while (j >= 0 && (t[j] == '#' || back > 0)) {
                back += t[j] == '#' ? 1 : -1;
                j -= 1;
            }

            if (i == -1 || j == -1 || s[i] != t[j]) {
                break;
            }
            i -= 1;
            j -= 1;
        }
        return i == -1 && j == -1;
    }
};