//  Tag: Math
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an integer num, return a string of its base 7 representation.
//   
//  Example 1:
//  Input: num = 100
//  Output: "202"
//  Example 2:
//  Input: num = -7
//  Output: "-10"
//  
//   
//  Constraints:
//  
//  -107 <= num <= 107
//  
//  

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) {
            return "0";
        }

        string sign = num>=0 ? "" : "-";
        string res = "";
        num = abs(num);
        while (num > 0) {
            int d = num % 7;
            num = num / 7;

            res = to_string(d) + res;
        }

        return sign + res;
    }
};