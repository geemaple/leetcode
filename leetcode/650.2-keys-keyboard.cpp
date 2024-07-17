//  Tag: Math, Dynamic Programming
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:
//  
//  Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
//  Paste: You can paste the characters which are copied last time.
//  
//  Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.
//   
//  Example 1:
//  
//  Input: n = 3
//  Output: 3
//  Explanation: Initially, we have one character 'A'.
//  In step 1, we use Copy All operation.
//  In step 2, we use Paste operation to get 'AA'.
//  In step 3, we use Paste operation to get 'AAA'.
//  
//  Example 2:
//  
//  Input: n = 1
//  Output: 0
//  
//   
//  Constraints:
//  
//  1 <= n <= 1000
//  
//  

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
            for (int j = 2; j <= n; ++j) {
                if (i % j == 0) {
                    dp[i] = j + dp[i/j];
                    break;
                } 
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        dp[1][0] = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                if (dp[i][j] == INT_MAX) {
                    continue;
                }

                if (j > 0 && i + j <=n) {
                    dp[i + j][j] = min(dp[i + j][j], dp[i][j] + 1);
                }

                if (i > j) {
                    dp[i][i] = min(dp[i][i], dp[i][j] + 1);
                }
            }
        }

        return *min_element(dp[n].begin(), dp[n].end());
    }
};

class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        for (int d = 2; d <= n; d++) {
            while (n % d == 0) {
                res += d;
                n /= d;
            }
        }
        return res;
    }
};