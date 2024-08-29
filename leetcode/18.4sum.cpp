//  Tag: Array, Two Pointers, Sorting
//  Time: O(N^3)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:
//  
//  0 <= a, b, c, d < n
//  a, b, c, and d are distinct.
//  nums[a] + nums[b] + nums[c] + nums[d] == target
//  
//  You may return the answer in any order.
//   
//  Example 1:
//  
//  Input: nums = [1,0,-1,0,-2,2], target = 0
//  Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
//  
//  Example 2:
//  
//  Input: nums = [2,2,2,2,2], target = 8
//  Output: [[2,2,2,2]]
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 200
//  -109 <= nums[i] <= 109
//  -109 <= target <= 109
//  
//  

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                long component = (long)target - nums[i] - nums[j];
                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    if (nums[left] + nums[right] == component) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        right--;
                    } else if (nums[left] + nums[right] > component) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }

                long component = (long)target - nums[i] - nums[j];
                unordered_map<long, int> history;
                for (int k = j + 1; k < n; k++) {
                    long tmp = component - nums[k];
                    if (history.count(tmp) > 0) {
                        res.push_back({nums[i], nums[j], nums[k], (int)tmp});
                        while (k + 1 < n && nums[k] == nums[k + 1]) {
                            k++;
                        }
                    } else {
                        history[nums[k]] = k;
                    }
                }
            }
        }

        return res;
    }
};

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        kSum(nums, 0, target, 4,  ans, res);
        return res;
    }

    void kSum(vector<int>& nums, int start, long target, int k, vector<int>& ans, vector<vector<int>> &res) {
        if (k == 2) {
            twoSum(nums, start, target, ans, res);
            return;
        }
        
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }
            
            ans.push_back(nums[i]);
            kSum(nums, i + 1, target - nums[i], k - 1, ans, res);
            ans.pop_back();
        }
    }

    void twoSum(vector<int>& nums, int start, long target, vector<int>& ans, vector<vector<int>> &res) {
        int left = start;
        int right = nums.size() - 1;

        while (left < right) {
            if (nums[left] + nums[right] == target) {
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                res.push_back(ans);
                ans.pop_back();
                ans.pop_back();

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
};