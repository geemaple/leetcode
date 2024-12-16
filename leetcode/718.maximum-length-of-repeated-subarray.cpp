//  Tag: Array, Binary Search, Dynamic Programming, Sliding Window, Rolling Hash, Hash Function
//  Time: O(NM)
//  Space: O(NM)
//  Ref: -
//  Note: -

//  Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
//   
//  Example 1:
//  
//  Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
//  Output: 3
//  Explanation: The repeated subarray with maximum length is [3,2,1].
//  
//  Example 2:
//  
//  Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
//  Output: 5
//  Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
//  
//   
//  Constraints:
//  
//  1 <= nums1.length, nums2.length <= 1000
//  0 <= nums1[i], nums2[i] <= 100
//  
//  

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int res = 0;

        // left to right
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    res = max(res, dp[i][j]);
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        int res = 0;

        // right to left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (nums1[i] == nums2[j]) {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int left = 0;
        int right = min(n, m);
        int res = 0;

        while (left < right) {
            int mid = left + (right - left) / 2 + 1;
            if (has_common_subarray(nums1, nums2, mid)) {
                res = mid;
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }

    int pow(int base, int exp, int mod) {
        int res = 1;
        int b = base % mod; 
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (1LL * res * b) % mod;
            }
            b = (1LL * b * b) % mod;
            exp /= 2;
        }
        return res;
    }

    bool has_common_subarray(vector<int>& nums1, vector<int>& nums2, int length) {

        int base = 101;
        int mod = 1e9 + 7;
        unordered_set<int> seen;
        int baseL = pow(base, length, mod);

        // first hash
        int hash1 = 0;
        for (int i = 0; i < length; i++) {
            hash1 = (1LL * hash1 * base + nums1[i]) % mod;
        }
        seen.insert(hash1);

        // rolling hash
        for (int i = length; i < nums1.size(); i++) {
            hash1 = (1LL * hash1 * base - 1LL * nums1[i - length] * baseL + nums1[i]) % mod;
            hash1 = (hash1 + mod) % mod;
            seen.insert(hash1);
        }

        int hash2 = 0;
        for (int j = 0; j < length; j++) {
            hash2 = (1LL * hash2 * base + nums2[j]) % mod;
        }
        if (seen.count(hash2) > 0) {
            return true;
        }

        for (int j = length; j < nums2.size(); j++) {
            hash2 = (1LL * hash2 * base - 1LL * nums2[j - length] * baseL + nums2[j]) % mod;
            hash2 = (hash2 + mod) % mod;
            if (seen.count(hash2) > 0) {
                return true;
            }
        }

        return false;
    }

};