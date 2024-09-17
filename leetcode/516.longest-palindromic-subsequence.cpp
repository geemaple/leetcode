//  Tag: String, Dynamic Programming
//  Time: O(N^2)
//  Space: O(N^2)
//  Ref: -
//  Note: -

//  Given a string s, find the longest palindromic subsequence's length in s.
//  A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.
//   
//  Example 1:
//  
//  Input: s = "bbbab"
//  Output: 4
//  Explanation: One possible longest palindromic subsequence is "bbbb".
//  
//  Example 2:
//  
//  Input: s = "cbbd"
//  Output: 2
//  Explanation: One possible longest palindromic subsequence is "bb".
//  
//   
//  Constraints:
//  
//  1 <= s.length <= 1000
//  s consists only of lowercase English letters.
//  
//  

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        for (int i = 1; i < n; i++) {
            dp[i - 1][i] = s[i - 1] == s[i] ? 2 : 1;
        }

        for (int l = 3; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> cache(n, vector<int>(n, -1));
        return helper(s, 0, n - 1, cache);
    }

    int helper(string &s, int i, int j, vector<vector<int>> &cache) {
        if (i > j) {
            return 0;
        }

        if (i == j) {
            return 1;
        }

        if (cache[i][j] == -1) {
            if (s[i] == s[j]) {
                cache[i][j] = helper(s, i + 1, j - 1, cache) + 2;
            } else {
                int left = helper(s, i + 1, j, cache);
                int right = helper(s, i, j - 1, cache);
                cache[i][j] = max(left, right);
            }
        }

        return cache[i][j];
    }
};