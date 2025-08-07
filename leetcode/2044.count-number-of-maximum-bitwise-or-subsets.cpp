//  Tag: Array, Backtracking, Bit Manipulation, Enumeration
//  Time: O(2^N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/Rcib_ZBbgp8

//  Given an integer array nums, find the maximum possible bitwise OR of a subset of nums and return the number of different non-empty subsets with the maximum bitwise OR.
//  An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b. Two subsets are considered different if the indices of the elements chosen are different.
//  The bitwise OR of an array a is equal to a[0] OR a[1] OR ... OR a[a.length - 1] (0-indexed).
//   
//  Example 1:
//  
//  Input: nums = [3,1]
//  Output: 2
//  Explanation: The maximum possible bitwise OR of a subset is 3. There are 2 subsets with a bitwise OR of 3:
//  - [3]
//  - [3,1]
//  
//  Example 2:
//  
//  Input: nums = [2,2,2]
//  Output: 7
//  Explanation: All non-empty subsets of [2,2,2] have a bitwise OR of 2. There are 23 - 1 = 7 total subsets.
//  
//  Example 3:
//  
//  Input: nums = [3,2,1,5]
//  Output: 6
//  Explanation: The maximum possible bitwise OR of a subset is 7. There are 6 subsets with a bitwise OR of 7:
//  - [3,5]
//  - [3,1,5]
//  - [3,2,5]
//  - [3,2,1,5]
//  - [2,5]
//  - [2,1,5]
//   
//  Constraints:
//  
//  1 <= nums.length <= 16
//  1 <= nums[i] <= 105
//  
//  

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int biggest = 0;
        for (auto x : nums) {
            biggest |= x;
        }

        unordered_map<int, int> res;
        dfs(nums, 0, 0, res);
        return res[biggest];
    }

    void dfs(vector<int>& nums, int i, int ans, unordered_map<int, int> &res) {
        if (i == nums.size()) {
            res[ans] += 1;
            return;
        }
        
        dfs(nums, i + 1, ans | nums[i], res);
        dfs(nums, i + 1, ans, res);
    }
};

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int biggest = 0;
        int dp[1 << 17] = {1};
        for (int x: nums) {
            for (int i = biggest; i >= 0; --i)
                dp[i | x] += dp[i];
            biggest |= x;
        }
        return dp[biggest];
    }
};