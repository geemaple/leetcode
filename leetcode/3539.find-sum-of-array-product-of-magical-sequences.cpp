//  Tag: Array, Math, Dynamic Programming, Bit Manipulation, Combinatorics, Bitmask
//  Time: O(MNK)
//  Space: O(MNK)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/TCDeVtpt-NA

//  You are given two integers, m and k, and an integer array nums.
//  A sequence of integers seq is called magical if:
//  
//  
//  seq has a size of m.
//  0 <= seq[i] < nums.length
//  The binary representation of 2seq[0] + 2seq[1] + ... + 2seq[m - 1] has k set bits.
//  
//  The array product of this sequence is defined as prod(seq) = (nums[seq[0]] * nums[seq[1]] * ... * nums[seq[m - 1]]).
//  Return the sum of the array products for all valid magical sequences.
//  Since the answer may be large, return it modulo 109 + 7.
//  A set bit refers to a bit in the binary representation of a number that has a value of 1.
//   
//  Example 1:
//  
//  Input: m = 5, k = 5, nums = [1,10,100,10000,1000000]
//  Output: 991600007
//  Explanation:
//  All permutations of [0, 1, 2, 3, 4] are magical sequences, each with an array product of 1013.
//  
//  Example 2:
//  
//  Input: m = 2, k = 2, nums = [5,4,3,2,1]
//  Output: 170
//  Explanation:
//  The magical sequences are [0, 1], [0, 2], [0, 3], [0, 4], [1, 0], [1, 2], [1, 3], [1, 4], [2, 0], [2, 1], [2, 3], [2, 4], [3, 0], [3, 1], [3, 2], [3, 4], [4, 0], [4, 1], [4, 2], and [4, 3].
//  
//  Example 3:
//  
//  Input: m = 1, k = 1, nums = [28]
//  Output: 28
//  Explanation:
//  The only magical sequence is [0].
//  
//   
//  Constraints:
//  
//  1 <= k <= m <= 30
//  1 <= nums.length <= 50
//  1 <= nums[i] <= 108
//  
//  

static int mod = 1e9 + 7;
static int comb[31][31]={{0}}; 
static int dp[31][31][50][32];
class Solution {
public:

    int magicalSum(int m, int k, vector<int>& nums) {
        calculate_comb();

        for(int i = 0; i < 31; i++) {
            for(int j = 0; j < 31; j++) {
                for(int s = 0; s < 50; s++) {
                    memset(dp[i][j][s], -1, sizeof(dp[i][j][s]));
                }
            }
        }
            
        return dfs(m, k, 0, 0, nums);
    }

    int dfs(int m, int k, int i, int carry, vector<int>& nums) {
        if (m < 0 || k < 0 || m + __builtin_popcount(carry) < k) {
            return 0;
        }

        if (m == 0) {
            return __builtin_popcount(carry) == k ? 1: 0;
        }

        if (i == nums.size()) {
            return 0;
        }

        if (dp[m][k][i][carry] == -1) {
            long long res = 0;
            for (int t = 0; t <= m; t++) {
                int ways = 1LL * comb[m][t] * dfs(m - t, k - ((carry + t) & 1), i + 1, (carry + t) >> 1, nums) % mod;
                int prod = 1LL * ways * pow(nums[i], t, mod) % mod;
                res = (res + prod) % mod;
            }

            dp[m][k][i][carry] = res;
        }

        return dp[m][k][i][carry];
    }

    int pow(int x, int p, int mod) {
        int res = 1;
        while (p > 0) {
            if (p % 2 == 1) {
                res = (1LL * res * x) % mod;
            }
            x = (1LL * x * x) % mod;
            p /= 2;
        }
        return res;
    }

    void calculate_comb() {
        if (comb[0][0] == 0) {
            comb[0][0] = 1;
            for (int i = 1; i <= 30; i++) {
                comb[i][0] = comb[i][i] = 1;
                for (int j = 1; j <= i / 2; j++) {
                    int res = comb[i - 1][j - 1] + comb[i - 1][j];
                    comb[i][j] = comb[i][i - j] = res;
                }
            }
        }
    }
};