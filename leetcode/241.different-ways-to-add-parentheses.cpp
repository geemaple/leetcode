//  Tag: Math, String, Dynamic Programming, Recursion, Memoization
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. You may return the answer in any order.
//  The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed 104.
//   
//  Example 1:
//  
//  Input: expression = "2-1-1"
//  Output: [0,2]
//  Explanation:
//  ((2-1)-1) = 0 
//  (2-(1-1)) = 2
//  
//  Example 2:
//  
//  Input: expression = "2*3-4*5"
//  Output: [-34,-14,-10,-10,10]
//  Explanation:
//  (2*(3-(4*5))) = -34 
//  ((2*3)-(4*5)) = -14 
//  ((2*(3-4))*5) = -10 
//  (2*((3-4)*5)) = -10 
//  (((2*3)-4)*5) = 10
//  
//   
//  Constraints:
//  
//  1 <= expression.length <= 20
//  expression consists of digits and the operator '+', '-', and '*'.
//  All the integer values in the input expression are in the range [0, 99].
//  
//  

class Solution {
public:
    unordered_map<string, vector<int>> cache;
    vector<int> diffWaysToCompute(string expression) {
        if (cache.count(expression)) {
            return cache[expression];
        }

        vector<int> res;
        int n = expression.size();
        for (int i = 0; i < n; i++) {
            char op = expression[i];
            if (op == '+' || op == '-' || op == '*') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1, n));

                for (auto l: left) {
                    for (auto r: right) {
                        if (op == '+') {
                            res.push_back(l + r);
                        } else if (op == '-') {
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }

        if (res.empty()) {
            res.push_back(stoi(expression));
        }

        cache[expression] = res;
        return res;
    }
};


class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<string> nums;
        vector<char> ops;
        
        int i = 0;
        for (int j = 0; j < n; ++j) {
            char op = expression[j];
            if (op == '+' || op == '-' || op == '*') {
                ops.push_back(op);
                nums.push_back(expression.substr(i, j - i));
                i = j + 1;
            }
        }
        nums.push_back(expression.substr(i, n - i));
        
        return solve(nums, ops);
    }

private:
    vector<int> solve(vector<string>& nums, vector<char>& ops) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));

        for (int i = 0; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (i == j) {
                    dp[i][i].push_back(stoi(nums[i]));
                } else {
                    for (int k = j; k < i; ++k) {
                        for (int l : dp[j][k]) {
                            for (int r : dp[k + 1][i]) {
                                if (ops[k] == '+') {
                                    dp[j][i].push_back(l + r);
                                } else if (ops[k] == '-') {
                                    dp[j][i].push_back(l - r);
                                } else {
                                    dp[j][i].push_back(l * r);
                                }
                            }
                        }
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};