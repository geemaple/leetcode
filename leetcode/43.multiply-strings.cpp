//  Tag: Math, String, Simulation
//  Time: O(NM)
//  Space: O(N+M)
//  Ref: -
//  Note: -

//  Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//  Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
//   
//  Example 1:
//  Input: num1 = "2", num2 = "3"
//  Output: "6"
//  Example 2:
//  Input: num1 = "123", num2 = "456"
//  Output: "56088"
//  
//   
//  Constraints:
//  
//  1 <= num1.length, num2.length <= 200
//  num1 and num2 consist of digits only.
//  Both num1 and num2 do not contain any leading zero, except the number 0 itself.
//  
//  

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int n = num1.size();
        int m = num2.size();
        vector<int> digits(n + m, 0);
        
        for(auto i = n - 1; i >= 0; i--) {
            for(auto j = m - 1; j >= 0; j--) {
                digits[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                digits[i + j] += digits[i + j + 1] / 10;
                digits[i + j + 1] %= 10;
            }
        }
        
        string res = "";
        for (int i = 0; i < m + n; i++) {
            if (digits[i] == 0 && res.size() == 0) {
                continue;
            }

            res += to_string(digits[i]);
        }
        
        return res;
    }
};