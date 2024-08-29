//  Tag: Array, Two Pointers, Sorting
//  Time: O(N^2)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
//  Notice that the solution set must not contain duplicate triplets.
//   
//  Example 1:
//  
//  Input: nums = [-1,0,1,2,-1,-4]
//  Output: [[-1,-1,2],[-1,0,1]]
//  Explanation: 
//  nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
//  nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
//  nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
//  The distinct triplets are [-1,0,1] and [-1,-1,2].
//  Notice that the order of the output and the order of the triplets does not matter.
//  
//  Example 2:
//  
//  Input: nums = [0,1,1]
//  Output: []
//  Explanation: The only possible triplet does not sum up to 0.
//  
//  Example 3:
//  
//  Input: nums = [0,0,0]
//  Output: [[0,0,0]]
//  Explanation: The only possible triplet sums up to 0.
//  
//   
//  Constraints:
//  
//  3 <= nums.length <= 3000
//  -105 <= nums[i] <= 105
//  
//  

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] == target) {
                    res.push_back({nums[left], nums[right], nums[i]});
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    left++;
                    right--;
                } else if (nums[left] + nums[right] > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            unordered_map<int, int> history;
            for (int j = i + 1; j < n; j++) {
                int tmp = target - nums[j];
                if (history.count(tmp) > 0) {
                    res.push_back({nums[i], nums[j], tmp});
                    while (j + 1 < n && nums[j] == nums[j + 1]) {
                        j++;
                    }
                } else {
                    history[nums[j]] = j;
                }
            }
        }
        return res;
    }
};