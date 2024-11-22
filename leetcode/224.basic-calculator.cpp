//  Tag: Math, String, Stack, Recursion
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
//  Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
//   
//  Example 1:
//  
//  Input: s = "1 + 1"
//  Output: 2
//  
//  Example 2:
//  
//  Input: s = " 2-1 + 2 "
//  Output: 3
//  
//  Example 3:
//  
//  Input: s = "(1+(4+5+2)-3)+(6+8)"
//  Output: 23
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 3 * 105
//  s consists of digits, '+', '-', '(', ')', and ' '.
//  s represents a valid expression.
//  '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
//  '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
//  There will be no two consecutive operators in the input.
//  Every number and running calculation will fit in a signed 32-bit integer.
//  
//  

class Solution {
public:
    int calculate(string s) {
        int num = 0;
        int res = 0;
        int sign = 1;
        stack<int> st;
        for (auto ch: s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '+' || ch == '-') {
                res += num * sign;
                sign = ch == '+' ? 1 : -1;
                num = 0;
            } else if (ch == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;
            } else if (ch == ')') {
                res += num * sign;
                num = 0;
                res *= st.top();
                st.pop();
                res += st.top();
                st.pop();
            }
        }

        return res + num * sign;
    }
};

class Solution {
public:
    int calculate(string s) {
        int i = 0;
        s = s + "+";
        return cal(s, i);
    }

    int cal(string &s, int &i) {
        int n = s.size();
        int pre = 0;
        int cur = 0;
        char op = '\0';

        while (i < n) {
            while (s[i] == ' '){ i++; }

            int num = 0;
            int sign = 1;
            if (s[i] == '-') {
                sign = -1;
                i++;
            }

            while (isdigit(s[i])) {
                cout << s[i] << endl;
                num = num * 10 + (s[i] - '0');
                i++;
            }

            while (s[i] == ' '){ i++; }

            if (s[i] == '(') {
                i++;
                num = cal(s, i);
            }

            num = num * sign;
            if (op == '\0') {
                cur = num;
            } else if (op == '+') {
                pre = pre + cur;
                cur = num;
            } else if (op == '-') {
                pre = pre + cur;
                cur = -num;
            }

            if (s[i] == ')') {
                i++;
                return pre + cur;
            }

            op = s[i];
            i++;
        }

        return pre + cur;
    }
};