//  Tag: Stack, String, Simulation
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: Leetcode-772

//  Implement a basic calculator to evaluate a simple expression string.
//  
//  
//  The expression string contains only non-negative integers, `+`, `-`, `*`, `/` operators , open `(` and closing parentheses `)` and empty spaces .
//  The integer division should truncate toward zero.
//  
//  You may assume that **the given expression is always valid**.
//  All intermediate results will be in the range of `[-2147483648, 2147483647]`
//  
//  **Example 1:**
//  ```
//  Input："1 + 1"
//  Output：2
//  Explanation：1 + 1 = 2
//  ```
//  
//  
//  **Example 2:**
//  ```
//  Input：" 6-4 / 2 "
//  Output：4
//  Explanation：4/2=2，6-2=4
//  ```
//  
//  Do not use the `eval` built-in library function.

class Solution {
public:
    /**
     * @param s: the expression string
     * @return: the answer
     */
    int calculate(string &s) {
        // Write your code here
        return helper(s, 0).first;
    }

    pair<int, int> helper(string &s, int i) {
        int left = 0; // stack except top
        int right = 0; // stack top
        int num = 0;
        char op = '+';
        while (i < s.size()) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + ch - '0';
            }

            if (ch == '(') {
                auto p = helper(s, i + 1);
                num = p.first;
                i = p.second;
            }

            if ((ch != ' ' && !isdigit(ch)) || i == s.size() - 1) {
                switch (op) {
                    case '+': left += right; right = num; break;
                    case '-': left += right; right = -num; break;
                    case '*': right *= num; break;
                    case '/': right /= num; break;
                }

                op = ch;
                num = 0;
            }

            if (ch == ')') {
                break;
            }
            i++;
        }
        return make_pair(left + right, i);
    }
};
