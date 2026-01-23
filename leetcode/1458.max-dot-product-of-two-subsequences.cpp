//  Tag: Array, Dynamic Programming
//  Time: O(NM)
//  Space: O(NM)
//  Ref: -
//  Note: -

//  Given two arrays nums1 and nums2.
//  Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
//  A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).
//   
//  Example 1:
//  
//  Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
//  Output: 18
//  Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
//  Their dot product is (2*3 + (-2)*(-6)) = 18.
//  Example 2:
//  
//  Input: nums1 = [3,-2], nums2 = [2,-6,7]
//  Output: 21
//  Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
//  Their dot product is (3*7) = 21.
//  Example 3:
//  
//  Input: nums1 = [-1,-1], nums2 = [1,1]
//  Output: -1
//  Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
//  Their dot product is -1.
//   
//  Constraints:
//  
//  1 <= nums1.length, nums2.length <= 500
//  -1000 <= nums1[i], nums2[i] <= 1000
//  
//  

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
  
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN / 2));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max({
                    dp[i - 1][j], 
                    dp[i][j - 1], 
                    max(0, dp[i - 1][j - 1]) + nums1[i - 1] * nums2[j - 1]
                });
            }
        }

        return dp[n][m];
    }
};

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = nums1[i] * nums2[j];
                if (i > 0 && j > 0) {
                    dp[i][j] += max(dp[i - 1][j - 1], 0);
                }

                if (i > 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                }

                if (j > 0) {
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }

            }
        }

        return dp[n - 1][m - 1];
    }
};