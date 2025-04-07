//  Tag: Array, Math, Dynamic Programming, Sorting
//  Time: O(N^2)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/1Rk51qxHSl0

//  Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
//  
//  answer[i] % answer[j] == 0, or
//  answer[j] % answer[i] == 0
//  
//  If there are multiple solutions, return any of them.
//   
//  Example 1:
//  
//  Input: nums = [1,2,3]
//  Output: [1,2]
//  Explanation: [1,3] is also accepted.
//  
//  Example 2:
//  
//  Input: nums = [1,2,4,8]
//  Output: [1,2,4,8]
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 1000
//  1 <= nums[i] <= 2 * 109
//  All the integers in nums are unique.
//  
//  

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> dp(size, 1);
        vector<int> pre(size, -1);
        int index = 0;
        
        for(auto i = 1; i < size; ++i) {
            for (auto j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
            
            if (dp[i] > dp[index]) {
                index = i;
            }
        }
        
        vector<int> result;
        while(index != -1) {
            result.push_back(nums[index]);
            index = pre[index];
        }
        
        return result; 
    }
};