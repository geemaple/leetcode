//  Tag: Array, Sliding Window, Sorting, Bucket Sort, Ordered Set
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  You are given an integer array nums and two integers indexDiff and valueDiff.
//  Find a pair of indices (i, j) such that:
//  
//  i != j,
//  abs(i - j) <= indexDiff.
//  abs(nums[i] - nums[j]) <= valueDiff, and
//  
//  Return true if such pair exists or false otherwise.
//   
//  Example 1:
//  
//  Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
//  Output: true
//  Explanation: We can choose (i, j) = (0, 3).
//  We satisfy the three conditions:
//  i != j --> 0 != 3
//  abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
//  abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
//  
//  Example 2:
//  
//  Input: nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
//  Output: false
//  Explanation: After trying all the possible pairs (i, j), we cannot satisfy the three conditions, so we return false.
//  
//   
//  Constraints:
//  
//  2 <= nums.length <= 105
//  -109 <= nums[i] <= 109
//  1 <= indexDiff <= nums.length
//  0 <= valueDiff <= 109
//  
//  

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        set<int> window;
        int k = indexDiff;

        for (int i = 0; i < n; i++) {
           
            auto low = window.lower_bound(nums[i] - valueDiff);
            if (low != window.end() && abs(nums[i] - *low) <= valueDiff) {
                return true;
            }
            window.insert(nums[i]);

            if (i >= k) {
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        unordered_map<int, int> window;
        double width = valueDiff + 1.0;
        int k = indexDiff;

        for (int i = 0; i < n; i++) {
            int bucket_id = floor(nums[i] / width);

            if (window.count(bucket_id) > 0) {
                return true;
            }

            if (window.count(bucket_id - 1) > 0 && abs(nums[i] - window[bucket_id - 1]) <= valueDiff) {
                return true;
            }

            if (window.count(bucket_id + 1) > 0 && abs(nums[i] - window[bucket_id + 1]) <= valueDiff) {
                return true;
            }

            window[bucket_id] = nums[i];
            if (i >= k) {
                int pre_id = floor(nums[i - k] / width);
                window.erase(pre_id);
            }
        }
        return false;
    }
};