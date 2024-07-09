//  Tag: Array, Backtracking
//  Time: O(2^N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
//  Each number in candidates may only be used once in the combination.
//  Note: The solution set must not contain duplicate combinations.
//   
//  Example 1:
//  
//  Input: candidates = [10,1,2,7,6,1,5], target = 8
//  Output: 
//  [
//  [1,1,6],
//  [1,2,5],
//  [1,7],
//  [2,6]
//  ]
//  
//  Example 2:
//  
//  Input: candidates = [2,5,2,1,2], target = 5
//  Output: 
//  [
//  [1,2,2],
//  [5]
//  ]
//  
//   
//  Constraints:
//  
//  1 <= candidates.length <= 100
//  1 <= candidates[i] <= 50
//  1 <= target <= 30
//  
//  

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<bool> visited(n, false);
        vector<int> tmp;
        dfs(candidates, target, visited, 0, tmp, res);
        return res;
    }

    void dfs(vector<int>& candidates, int remain, vector<bool>& visited, int start, vector<int>& tmp, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(tmp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > 0 && candidates[i] == candidates[i - 1] && !visited[i - 1]) {
                continue;
            }

            if (!visited[i] && remain - candidates[i] >= 0) {
                visited[i] = true;
                tmp.push_back(candidates[i]);
                dfs(candidates, remain - candidates[i], visited, i + 1, tmp, res);
                tmp.pop_back();
                visited[i] = false;
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(candidates, target, 0, tmp, res);
        return res;
    }

    void dfs(vector<int>& candidates, int remain, int start, vector<int>& tmp, vector<vector<int>>& res) {
        if (remain == 0) {
            res.push_back(tmp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            if (remain - candidates[i] >= 0) {
                tmp.push_back(candidates[i]);
                dfs(candidates, remain - candidates[i], i + 1, tmp, res);
                tmp.pop_back();
            }
        }
    }
};