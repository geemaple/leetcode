//  Tag: Array, Hash Table, Sliding Window
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
//  
//  The length of the subarray is k, and
//  All the elements of the subarray are distinct.
//  
//  Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.
//  A subarray is a contiguous non-empty sequence of elements within an array.
//   
//  Example 1:
//  
//  Input: nums = [1,5,4,2,9,9,9], k = 3
//  Output: 15
//  Explanation: The subarrays of nums with length 3 are:
//  - [1,5,4] which meets the requirements and has a sum of 10.
//  - [5,4,2] which meets the requirements and has a sum of 11.
//  - [4,2,9] which meets the requirements and has a sum of 15.
//  - [2,9,9] which does not meet the requirements because the element 9 is repeated.
//  - [9,9,9] which does not meet the requirements because the element 9 is repeated.
//  We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions
//  
//  Example 2:
//  
//  Input: nums = [4,4,4], k = 3
//  Output: 0
//  Explanation: The subarrays of nums with length 3 are:
//  - [4,4,4] which does not meet the requirements because the element 4 is repeated.
//  We return 0 because no subarrays meet the conditions.
//  
//   
//  Constraints:
//  
//  1 <= k <= nums.length <= 105
//  1 <= nums[i] <= 105
//  
//  

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> counter;
        long long res = 0;
        long long total = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            total += nums[j];
            counter[nums[j]] += 1;
            if (j - i + 1 == k) {
                if (counter.size() == k) {
                    res = max(res, total);
                }
                total -= nums[i];
                counter[nums[i]] -= 1;
                if (counter[nums[i]] == 0) {
                    counter.erase(nums[i]);
                }
                i += 1;
            }
        }

        return res;
    }
};

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> visited;
        long long res = 0;
        long long total = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (visited.count(nums[j]) == 0) {
                total += nums[j];
                visited.insert(nums[j]);
                if (j - i + 1 == k) {
                    if (visited.size() == k) {
                        res = max(res, total);
                    }
                    total -= nums[i];
                    visited.erase(nums[i]);
                    i += 1;
                }
            } else {
                while (nums[i] != nums[j]) {
                    total -= nums[i];
                    visited.erase(nums[i]);
                    i += 1;
                }
                i += 1;
            }
        }

        return res;
    }
};

    