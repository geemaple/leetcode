//  Tag: Dynamic Programming, Prefix Sum
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  You are given 3 positive integers zero, one, and limit.
//  A binary array arr is called stable if:
//  
//  The number of occurrences of 0 in arr is exactly zero.
//  The number of occurrences of 1 in arr is exactly one.
//  Each subarray of arr with a size greater than limit must contain both 0 and 1.
//  
//  Return the total number of stable binary arrays.
//  Since the answer may be very large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: zero = 1, one = 1, limit = 2
//  Output: 2
//  Explanation:
//  The two possible stable binary arrays are [1,0] and [0,1].
//  
//  Example 2:
//  
//  Input: zero = 1, one = 2, limit = 1
//  Output: 1
//  Explanation:
//  The only possible stable binary array is [1,0,1].
//  
//  Example 3:
//  
//  Input: zero = 3, one = 3, limit = 2
//  Output: 14
//  Explanation:
//  All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].
//  
//   
//  Constraints:
//  
//  1 <= zero, one, limit <= 1000
//  
//  

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int mod = 1'000'000'007;
        int L = limit + 1;

        vector<vector<int>> dp0(zero + 1, vector<int>(one + 1, 0)); // i 0s + j 1s ending with 0
        vector<vector<int>> dp1(zero + 1, vector<int>(one + 1, 0)); // i 0s + j 1s ending with 1

        // Base cases: only zeros or only ones => only one string if len <= min(limit, zero/one)
        for (int i = 1; i <= min(zero, limit); ++i) dp0[i][0] = 1;
        for (int j = 1; j <= min(one, limit); ++j) dp1[0][j] = 1;

        // DP iterations
        for (int i = 1; i <= zero; ++i) {
            for (int j = 1; j <= one; ++j) {
                dp0[i][j] = (1LL * dp0[i-1][j] + dp1[i-1][j] - (i >= L ? dp1[i-L][j] : 0)) % mod;
                dp1[i][j] = (1LL * dp1[i][j-1] + dp0[i][j-1] - (j >= L ? dp0[i][j-L] : 0)) % mod;

                // Fix negatives
                dp0[i][j] = (dp0[i][j] + mod) % mod;
                dp1[i][j] = (dp1[i][j] + mod) % mod;
            }
        }

        return (dp0[zero][one] + dp1[zero][one]) % mod;
    }
};