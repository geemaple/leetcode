//  Tag: Math, String, Bit Manipulation, Simulation
//  Time: O(M+N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given two binary strings a and b, return their sum as a binary string.
//   
//  Example 1:
//  Input: a = "11", b = "1"
//  Output: "100"
//  Example 2:
//  Input: a = "1010", b = "1011"
//  Output: "10101"
//  
//   
//  Constraints:
//  
//  1 <= a.length, b.length <= 104
//  a and b consist only of '0' or '1' characters.
//  Each string does not contain leading zeros except for the zero itself.
//  
//  

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int l = i >= 0 ? a[i] - '0' : 0;
            int r = j >= 0 ? b[j] - '0' : 0;
            int tmp = l + r + carry;
            char digit = tmp % 2;
            carry = tmp / 2;
            res = to_string(digit) + res;
            i--;
            j--;
        }

        return res;
    }
};