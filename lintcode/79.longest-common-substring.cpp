//  Tag: Dynamic Programming/DP, Two Sequences DP
//  Time: O(NM)
//  Space: O(NM)
//  Ref: -
//  Note: -

//  Given two strings, find the longest common substring.
//  
//  Return the length of it.
//  
//  **Example 1:**  
//   
//  Input:  
//  ``` 
//  stringA = "ABCD"
//  stringB = "CBCE"
//  ``` 
//  Output:  
//  ``` 
//  2
//  ``` 
//  Explanation:  
//  
//  Longest common substring is "BC"
//  
//  **Example 2:**  
//   
//  Input:  
//  ``` 
//  stringA = "ABCD"
//  stringB = "EACB"
//  ``` 
//  Output:  
//  ``` 
//  1
//  ``` 
//  Explanation:  
//  
//   Longest common substring is 'A' or 'C' or 'B'
//  
//  The characters in **substring** should occur continuously in original string. This is different with **subsequence**.

class Solution {
public:
    /**
     * @param a: A string
     * @param b: A string
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &a, string &b) {
        // write your code here
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    if (i > 0 && j > 0) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    } else {
                        dp[i][j] = 1;
                    }

                    res = max(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};