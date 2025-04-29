//  Tag: Array, Two Pointers, Sorting
//  Time: O(N^2)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
//  Return the sum of the three integers.
//  You may assume that each input would have exactly one solution.
//   
//  Example 1:
//  
//  Input: nums = [-1,2,1,-4], target = 1
//  Output: 2
//  Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//  
//  Example 2:
//  
//  Input: nums = [0,0,0], target = 1
//  Output: 0
//  Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
//  
//   
//  Constraints:
//  
//  3 <= nums.length <= 500
//  -1000 <= nums[i] <= 1000
//  -104 <= target <= 104
//  
//  

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int result = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
    
        for (int k = 2; k < n; k++) {
            int l = 0;
            int r = k - 1;
            while (l < r) {
                int tmp = nums[l] + nums[r] + nums[k];
                if (abs(target - result) > abs(target - tmp)) {
                    result = tmp;
                }

                if (tmp == target) {
                    break;
                } else if(tmp > target){
                    r -= 1;
                } else {
                    l += 1;
                }
            }
        }
        return result;
    }
};
