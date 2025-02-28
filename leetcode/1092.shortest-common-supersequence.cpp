//  Tag: String, Dynamic Programming
//  Time: O(NM)
//  Space: O(NM)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/5fRF2U2DdEY

//  Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.
//  A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
//   
//  Example 1:
//  
//  Input: str1 = "abac", str2 = "cab"
//  Output: "cabac"
//  Explanation: 
//  str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
//  str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
//  The answer provided is the shortest such string that satisfies these properties.
//  
//  Example 2:
//  
//  Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
//  Output: "aaaaaaaa"
//  
//   
//  Constraints:
//  
//  1 <= str1.length, str2.length <= 1000
//  str1 and str2 consist of lowercase English letters.
//  
//  

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        vector<char> lcs(dp[n][m]);
        int i = n;
        int j = m;
        while (i > 0 && j > 0 && dp[i][j] > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs[dp[i][j] - 1] = str1[i - 1];
                i -= 1;
                j -= 1;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i -= 1;
            } else {
                j -= 1;
            }
        }

        string res;
        i = 0;
        j = 0;
        for (auto &ch: lcs) {
            while (str1[i] != ch) {
                res += str1[i];
                i += 1;
            }

            while (str2[j] != ch) {
                res += str2[j];
                j += 1;
            }

            res += ch;
            i += 1;
            j += 1;
        }

        if (i < n) {
            res += str1.substr(i);
        }

        if (j < m) {
            res += str2.substr(j);
        }

        return res;
    }
};