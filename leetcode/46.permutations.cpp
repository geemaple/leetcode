//  Tag: Array, Backtracking
//  Time: O(N!)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
//   
//  Example 1:
//  Input: nums = [1,2,3]
//  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//  Example 2:
//  Input: nums = [0,1]
//  Output: [[0,1],[1,0]]
//  Example 3:
//  Input: nums = [1]
//  Output: [[1]]
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 6
//  -10 <= nums[i] <= 10
//  All the integers of nums are unique.
//  
//  

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(nums, 0, res);
        return res;
    }

    void dfs(vector<int>& nums, int level, vector<vector<int>> &ans) {
        if (level == nums.size() - 1) {
            ans.push_back(nums);
        }

        for (int i = level; i < nums.size(); i++) {
            swap(nums[i], nums[level]);
            dfs(nums, level + 1, ans);
            swap(nums[i], nums[level]);
        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_set<int> visited;
        vector<int> tmp;
        dfs(nums, visited, tmp, res);
        return res;
    }

    void dfs(vector<int>& nums, unordered_set<int> &visited, vector<int> &tmp, vector<vector<int>> &ans) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (visited.count(i) == 0) {
                visited.insert(i);
                tmp.push_back(nums[i]);
                dfs(nums, visited, tmp, ans);
                tmp.pop_back();
                visited.erase(i);
            }
        }
    }
};