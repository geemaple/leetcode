//  Tag: String, Dynamic Programming
//  Time: O(NM)
//  Space: O(NM)
//  Ref: -
//  Note: -

//  Given two strings s and t, return the number of distinct subsequences of s which equals t.
//  The test cases are generated so that the answer fits on a 32-bit signed integer.
//   
//  Example 1:
//  
//  Input: s = "rabbbit", t = "rabbit"
//  Output: 3
//  Explanation:
//  As shown below, there are 3 ways you can generate "rabbit" from s.
//  rabbbit
//  rabbbit
//  rabbbit
//  
//  Example 2:
//  
//  Input: s = "babgbag", t = "bag"
//  Output: 5
//  Explanation:
//  As shown below, there are 5 ways you can generate "bag" from s.
//  babgbag
//  babgbag
//  babgbag
//  babgbag
//  babgbag
//   
//  Constraints:
//  
//  1 <= s.length, t.length <= 1000
//  s and t consist of English letters.
//  
//  

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<long>> dp(n + 1, vector<long>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <=m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = (j == 0) ? 1: 0;
                } else {
                    if (s[i - 1] == t[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][m];
    }
};