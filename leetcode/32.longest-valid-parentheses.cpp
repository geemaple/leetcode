//  Tag: String, Dynamic Programming, Stack
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
//   
//  Example 1:
//  
//  Input: s = "(()"
//  Output: 2
//  Explanation: The longest valid parentheses substring is "()".
//  
//  Example 2:
//  
//  Input: s = ")()())"
//  Output: 4
//  Explanation: The longest valid parentheses substring is "()()".
//  
//  Example 3:
//  
//  Input: s = ""
//  Output: 0
//  
//   
//  Constraints:
//  
//  0 <= s.length <= 3 * 104
//  s[i] is '(', or ')'.
//  
//  

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = i >= 2 ? dp[i - 2] + 2 : 2;
                } else {
                    int j = i - dp[i - 1] - 1;
                    if (j >= 0 && s[j] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (j >= 1) {
                            dp[i] += dp[j - 1];
                        }
                    }
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int n = s.size();
        int left = 0;
        int right = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left += 1;
            } else {
                right += 1;
            }

            if (left == right) {
                res = max(res, right * 2);
            } else if (right > left) {
                left = 0;
                right = 0;
            }
        }

        left = 0;
        right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ')') {
                right += 1;
            } else {
                left += 1;
            }
            
            if (left == right) {
                res = max(res, right * 2); 
            } else if (left > right) {
                left = 0;
                right = 0;
            }
        }

        return res;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(-1);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()){
                    st.push(i);
                }
                res = max(res, i - st.top());
            }
        }
        return res;
    }
};