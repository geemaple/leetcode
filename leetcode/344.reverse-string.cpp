//  Tag: Two Pointers, String
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Write a function that reverses a string. The input string is given as an array of characters s.
//  You must do this by modifying the input array in-place with O(1) extra memory.
//   
//  Example 1:
//  Input: s = ["h","e","l","l","o"]
//  Output: ["o","l","l","e","h"]
//  Example 2:
//  Input: s = ["H","a","n","n","a","h"]
//  Output: ["h","a","n","n","a","H"]
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 105
//  s[i] is a printable ascii character.
//  
//  

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;

            l++;
            r--;
        }
    }
};