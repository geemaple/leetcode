//  Tag: Array, Hash Table, Sliding Window, Prefix Sum
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.
//  A subarray is a contiguous part of the array.
//   
//  Example 1:
//  
//  Input: nums = [1,0,1,0,1], goal = 2
//  Output: 4
//  Explanation: The 4 subarrays are bolded and underlined below:
//  [1,0,1,0,1]
//  [1,0,1,0,1]
//  [1,0,1,0,1]
//  [1,0,1,0,1]
//  
//  Example 2:
//  
//  Input: nums = [0,0,0,0,0], goal = 0
//  Output: 15
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 3 * 104
//  nums[i] is either 0 or 1.
//  0 <= goal <= nums.length
//  
//  

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return count(nums, goal) - count(nums, goal - 1);
    }
    
    int count(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int res = 0;
        int total = 0;
        for (int j = 0; j < n; j++) {
            total += nums[j];
            while (i <= j && total > k) {
                total -= nums[i];
                i += 1;
            }
            res += j - i + 1;
        }
        return res;
    }
};

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> counter;
        counter[0] = 1;
        int total = 0;
        int res = 0;
        for (auto x: nums) {
            total += x;
            res += counter[total - goal];
            counter[total] += 1;
        }
        return res;
    }
};