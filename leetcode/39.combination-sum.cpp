class Solution {
private:
    void helper(vector<int>& candidates, int start, int sum, int target, vector<int>& ans, vector<vector<int>>& res)
    {
        if (sum >= target)
        {
            if (sum == target)
            {
                res.push_back(ans);
            }
            return;
        }
        
        for (auto i = start; i < candidates.size(); ++i)
        {
            ans.push_back(candidates[i]);
            helper(candidates, i, sum + candidates[i], target, ans, res);
            ans.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> ans;
        
        helper(candidates, 0, 0, target, ans, res);
        return res;
    }
};