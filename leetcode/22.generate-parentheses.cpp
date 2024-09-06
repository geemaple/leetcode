//  Tag: String, Dynamic Programming, Backtracking
//  Time: O(2^N)
//  Space: O(N)
//  Ref: -
//  Note: Catalan Number

//  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//   
//  Example 1:
//  Input: n = 3
//  Output: ["((()))","(()())","(())()","()(())","()()()"]
//  Example 2:
//  Input: n = 1
//  Output: ["()"]
//  
//   
//  Constraints:
//  
//  1 <= n <= 8
//  
//  

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(0, 0, n, "", res);
        return res;
    }

    void helper(int left, int right, int n, string ans, vector<string>& res) {
        if (left + right == n * 2) {
            res.push_back(ans);
            return;
        }

        if (left < n) {
            helper(left + 1, right, n, ans + "(", res);
        }

        if (right < left) { 
            helper(left, right + 1, n, ans + ")", res);
        }
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0] = {""};

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                vector<string>& left = dp[j];
                vector<string>& right = dp[i - j - 1];
                for (auto &l: left) {
                    for (auto &r: right) {
                        dp[i].push_back("(" + l + ")" + r);
                    }
                }
            }
        }

        return dp[n];
    }
};