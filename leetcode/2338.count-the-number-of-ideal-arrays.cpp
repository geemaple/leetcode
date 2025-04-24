//  Tag: Math, Dynamic Programming, Combinatorics, Number Theory
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: Video: https://youtu.be/tAIPbGRZojY

//  You are given two integers n and maxValue, which are used to describe an ideal array.
//  A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:
//  
//  Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
//  Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
//  
//  Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.
//   
//  Example 1:
//  
//  Input: n = 2, maxValue = 5
//  Output: 10
//  Explanation: The following are the possible ideal arrays:
//  - Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
//  - Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
//  - Arrays starting with the value 3 (1 array): [3,3]
//  - Arrays starting with the value 4 (1 array): [4,4]
//  - Arrays starting with the value 5 (1 array): [5,5]
//  There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
//  
//  Example 2:
//  
//  Input: n = 5, maxValue = 3
//  Output: 11
//  Explanation: The following are the possible ideal arrays:
//  - Arrays starting with the value 1 (9 arrays): 
//     - With no other distinct values (1 array): [1,1,1,1,1] 
//     - With 2nd distinct value 2 (4 arrays): [1,1,1,1,2], [1,1,1,2,2], [1,1,2,2,2], [1,2,2,2,2]
//     - With 2nd distinct value 3 (4 arrays): [1,1,1,1,3], [1,1,1,3,3], [1,1,3,3,3], [1,3,3,3,3]
//  - Arrays starting with the value 2 (1 array): [2,2,2,2,2]
//  - Arrays starting with the value 3 (1 array): [3,3,3,3,3]
//  There are a total of 9 + 1 + 1 = 11 distinct ideal arrays.
//  
//   
//  Constraints:
//  
//  2 <= n <= 104
//  1 <= maxValue <= 104
//  
//  

int comb[10001][14] = { 1 }, dp[10001][14] = {}, mod = 1000000007;
class Solution {
public: 
    int idealArrays(int n, int maxValue) {
        if (comb[1][1] == 0) { // one-time computation.
            for (int s = 1; s <= 10000; ++s)
                for (int r = 0; r < 14; ++r)
                    comb[s][r] = r == 0 ? 1 : (comb[s - 1][r - 1] + comb[s - 1][r]) % mod;
                    
            for (int div = 1; div <= 10000; ++div) { // Sieve of Eratosthenes
                dp[div][0] += 1;
                for (int i = 2 * div; i <= 10000; i += div)
                    for (int bars = 0; dp[div][bars]; ++bars)
                        dp[i][bars + 1] += dp[div][bars];
            }
        }
        int res = 0;
        for (int i = 1; i <= maxValue; ++i)
            for (int bars = 0; bars < min(14, n) && dp[i][bars]; ++bars)
                res = (1LL * dp[i][bars] * comb[n - 1][bars] + res) % mod;
        return res;
    }
};

int comb[10001][14] = {1};
class Solution {
public:
    int idealArrays(int n, int maxValue) {
        int k = min(n, 14);
        int mod = 1e9 + 7;
        unordered_map<int, vector<int>> divisors;
        for (int i = 1; i <= maxValue; i++) {
            for (int j = 2 * i; j <= maxValue; j += i) {
                divisors[j].push_back(i);
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(maxValue + 1, 0));
        for (int i = 1; i <= maxValue; i++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= k; i++) {
            for (int j = 1; j <= maxValue; j++) {
                for (auto d: divisors[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][d]) % mod;
                }
            }
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= maxValue; j++) {
                dp[i][0] = (dp[i][0] + dp[i][j]) % mod;
            }
        } 

        if (comb[1][1] == 0) {
            for (int i = 1; i <= 10000; i++) {
                for (int j = 0; j < 14; j++) {
                    comb[i][j] = j == 0 ? 1 : (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= k; i++) {
            if (dp[i][0] > 0) {
                res = (res + 1LL * comb[n - 1][i - 1] * dp[i][0] ) % mod;
            }
        }

        return res;
    }
};