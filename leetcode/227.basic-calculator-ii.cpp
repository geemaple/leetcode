//  Tag: Math, String, Stack
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  Given a string s which represents an expression, evaluate this expression and return its value. 
//  The integer division should truncate toward zero.
//  You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
//  Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
//   
//  Example 1:
//  Input: s = "3+2*2"
//  Output: 7
//  Example 2:
//  Input: s = " 3/2 "
//  Output: 1
//  Example 3:
//  Input: s = " 3+5 / 2 "
//  Output: 5
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 3 * 105
//  s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
//  s represents a valid expression.
//  All the integers in the expression are non-negative integers in the range [0, 231 - 1].
//  The answer is guaranteed to fit in a 32-bit integer.
//  
//  

class Solution {
public:
    int calculate(string s) {
        s += '+';
        int n = s.size();
        int left = 0;  // stack sum except top
        int right = 0; // stack top
        char op = '+';
        int num = 0;

        for (auto i = 0; i < n; i++) {
            if (s[i] == ' ') {
                continue;
            }
            
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else {
                switch (op) {
                    case '+': left += right; right = num; break;
                    case '-': left += right; right = -num; break;
                    case '*': right *= num; break;
                    case '/': right /= num; break;
                }
                num = 0;
                op = s[i];
            }
        }

        return left + right;
    }
};