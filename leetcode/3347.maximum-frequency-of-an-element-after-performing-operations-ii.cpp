//  Tag: Array, Binary Search, Sliding Window, Sorting, Prefix Sum
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/Ns8dBIYMpNY

//  You are given an integer array nums and two integers k and numOperations.
//  You must perform an operation numOperations times on nums, where in each operation you:
//  
//  Select an index i that was not selected in any previous operations.
//  Add an integer in the range [-k, k] to nums[i].
//  
//  Return the maximum possible frequency of any element in nums after performing the operations.
//   
//  Example 1:
//  
//  Input: nums = [1,4,5], k = 1, numOperations = 2
//  Output: 2
//  Explanation:
//  We can achieve a maximum frequency of two by:
//  
//  Adding 0 to nums[1], after which nums becomes [1, 4, 5].
//  Adding -1 to nums[2], after which nums becomes [1, 4, 4].
//  
//  
//  Example 2:
//  
//  Input: nums = [5,11,20,20], k = 5, numOperations = 1
//  Output: 2
//  Explanation:
//  We can achieve a maximum frequency of two by:
//  
//  Adding 0 to nums[1].
//  
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 105
//  1 <= nums[i] <= 109
//  0 <= k <= 109
//  0 <= numOperations <= nums.length
//  
//  

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, int> counter;
        int res = 0;
        int i = 0;
        int j = 0;
        for (auto &x: nums) {
            while (j < n && nums[j] <= x + k) {
                counter[nums[j]] += 1;
                j += 1;
            }

            while (i < n && nums[i] < x - k) {
                counter[nums[i]] -= 1;
                i += 1;
            }

            int cur = min(j - i, counter[x] + numOperations);
            res = max(res, cur);
        }

        for (int i = 0, j = 0; j < n; j++) {
            while (nums[i] + k + k < nums[j]) {
                i += 1;
            }
            int cur = min(j - i + 1, numOperations);
            res = max(res, cur);
        }
        return res;
    }
};

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> counter;
        map<int, int> sweep;
        for (auto &x: nums) {
            counter[x] += 1; 
            sweep[max(0, x - k)] += 1;
            sweep[x + k + 1] -= 1;

            if (sweep.find(x) == sweep.end()) {
                sweep[x] = 0;
            }
        }

        int res = 0;
        int prefix = 0;
        for (auto &[x, c]: sweep) {
            prefix += c;
            res = max(res, min(numOperations + counter[x], prefix));
        }
        return res;
    }
};

