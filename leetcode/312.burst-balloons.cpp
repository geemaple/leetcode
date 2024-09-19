//  Tag: Array, Dynamic Programming
//  Time: O(N^3)
//  Space: O(N^2)
//  Ref: -
//  Note: -

//  You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
//  If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
//  Return the maximum coins you can collect by bursting the balloons wisely.
//   
//  Example 1:
//  
//  Input: nums = [3,1,5,8]
//  Output: 167
//  Explanation:
//  nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
//  coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
//  Example 2:
//  
//  Input: nums = [1,5]
//  Output: 10
//  
//   
//  Constraints:
//  
//  n == nums.length
//  1 <= n <= 300
//  0 <= nums[i] <= 100
//  
//  

class Solution {
public:
    
    int maxCoins(vector<int>& nums) {

        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();       
        vector<vector<int>> cache(n, vector<int>(n, -1));

        return burst(nums, 1, n - 2, cache);
    }

    int burst(vector<int>& nums, int left, int right, vector<vector<int>>& cache) {
        if (left > right) {
            return 0;
        }

        if (cache[left][right] != -1) {
            return cache[left][right];
        }

        int res = 0;
        for (int k = left; k <= right; k++) {
            int point = nums[left - 1] * nums[k] * nums[right + 1] + burst(nums, left, k - 1, cache) + burst(nums, k + 1, right, cache);
            if (point > res) {
                res = point;
            }
        }

        cache[left][right] = res;
        return res;
    }
};

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();       
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int l = 1; l <= n - 2; l++) {
            for (int i = 1; i < n - l; i++) {
                int j = i + l - 1;
                for (int k = i; k <= j; k++) {
                    int p = nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j];
                    if (p > dp[i][j]) {
                        dp[i][j] = p;
                    }
                }
            }

        }

        return dp[1][n - 2];
    }
};