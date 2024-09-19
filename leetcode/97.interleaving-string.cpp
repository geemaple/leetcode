//  Tag: String, Dynamic Programming
//  Time: O(NM)
//  Space: O(M)
//  Ref: -
//  Note: Prove |n - m| <= 1

//  Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.
//  An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:
//  
//  s = s1 + s2 + ... + sn
//  t = t1 + t2 + ... + tm
//  |n - m| <= 1
//  The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
//  
//  Note: a + b is the concatenation of strings a and b.
//   
//  Example 1:
//  
//  
//  Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//  Output: true
//  Explanation: One way to obtain s3 is:
//  Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
//  Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
//  Since s3 can be obtained by interleaving s1 and s2, we return true.
//  
//  Example 2:
//  
//  Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//  Output: false
//  Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
//  
//  Example 3:
//  
//  Input: s1 = "", s2 = "", s3 = ""
//  Output: true
//  
//   
//  Constraints:
//  
//  0 <= s1.length, s2.length <= 100
//  0 <= s3.length <= 200
//  s1, s2, and s3 consist of lowercase English letters.
//  
//   
//  Follow up: Could you solve it using only O(s2.length) additional memory space?
//  

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        int n = s1.size();
        int m = s2.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <=m; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                } else {
                    if (i > 0 && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) {
                        dp[i][j] = true;
                    }

                    if (j > 0 && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) {
                        dp[i][j] = true;
                    }
                }
            }
        }

        return dp[n][m];
    }
};

// follow up
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) {
            return false;
        }

        int n = s1.size();
        int m = s2.size();
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        for (int j = 1; j <= m; j++) {
            dp[j] = dp[j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= n; i++) {
            dp[0] = dp[0] && s1[i - 1] == s3[i - 1];

            for (int j = 1; j <=m; j++) {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[m];
    }
};