//  Tag: Array, Backtracking
//  Time: O(N!)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
//   
//  Example 1:
//  
//  Input: nums = [1,1,2]
//  Output:
//  [[1,1,2],
//   [1,2,1],
//   [2,1,1]]
//  
//  Example 2:
//  
//  Input: nums = [1,2,3]
//  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
//  
//   
//  Constraints:
//  
//  1 <= nums.length <= 8
//  -10 <= nums[i] <= 10
//  
//  

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> visited(n, false);
        vector<vector<int>> res;
        vector<int> tmp;

        dfs(nums, visited, tmp, res);
        return res;
    }

    void dfs(vector<int>& nums, vector<bool>& visited, vector<int>& tmp, vector<vector<int>>& res) {
        if (tmp.size() == nums.size()) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
                continue;
            }

            if (!visited[i]) {
                visited[i] = true;
                tmp.push_back(nums[i]);
                dfs(nums, visited, tmp, res);
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }
};