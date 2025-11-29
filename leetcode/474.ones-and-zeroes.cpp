//  Tag: Array, String, Dynamic Programming
//  Time: O(KMN)
//  Space: O(MN)
//  Ref: -
//  Note: -

//  You are given an array of binary strings strs and two integers m and n.
//  Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
//  A set x is a subset of a set y if all elements of x are also elements of y.
//   
//  Example 1:
//  
//  Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
//  Output: 4
//  Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
//  Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
//  {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
//  
//  Example 2:
//  
//  Input: strs = ["10","0","1"], m = 1, n = 1
//  Output: 2
//  Explanation: The largest subset is {"0", "1"}, so the answer is 2.
//  
//   
//  Constraints:
//  
//  1 <= strs.length <= 600
//  1 <= strs[i].length <= 100
//  strs[i] consists only of digits '0' and '1'.
//  1 <= m, n <= 100
//  
//  

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int k = strs.size();
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

        for (int i = 1; i <= k; i++) {
            auto [zeros, ones] = count01(strs[i - 1]);
            for (int z = 0; z <= m; z++) {
                for(int o = 0; o <= n; o++) {
                    if (zeros <= z && ones <= o) {
                        dp[i][z][o] = max(dp[i - 1][z][o], dp[i - 1][z - zeros][o - ones] + 1);
                    } else {
                        dp[i][z][o] = dp[i - 1][z][o];
                    }
                }
            }
        }   
        return dp[k][m][n];
    }

    pair<int, int> count01(const string &s) {
        int zeros = 0;
        for (auto ch: s) {
            if (ch == '0') {
                zeros++;
            }
        }
        return make_pair(zeros, s.size() - zeros);
    } 
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return dfs(strs, 0, m, n, dp);
    }

    int dfs(vector<string>& strs, int i, int m, int n, vector<vector<vector<int>>> &dp) {
        if (i == strs.size()) {
            return 0;
        }

        if (dp[i][m][n] == -1) {
            int zero = count(strs[i].begin(), strs[i].end(), '0');
            int one = strs[i].size() - zero;
            int res = dfs(strs, i + 1, m, n, dp);
            if (zero <= m && one <= n) {
                res = max(res, dfs(strs, i + 1, m - zero, n - one, dp) + 1);
            }

            dp[i][m][n] = res;
        }
        return dp[i][m][n];
    }
};

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int k = strs.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= k; i++) {
            string s = strs[i - 1];
            int zeros = count(s.begin(), s.end(), '0');
            int ones = s.size() - zeros;

            for (int z = m; z >= zeros; z--) {
                for(int o = n; o >= ones; o--) {
                    dp[z][o] = max(dp[z][o],  dp[z - zeros][o - ones] + 1);
                }
            }
        }   
        return dp[m][n];
    }
};