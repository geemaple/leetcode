class Solution {
private:
    void helper(vector<int>& nums, unordered_set<int> &visited, vector<int> &ans, vector<vector<int>>& res)
    {
        if (ans.size() == nums.size())
        {
            res.push_back(ans);
        }
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (visited.count(i) != 0)
            {
                continue;
            }
            
            if (i > 0 && nums[i] == nums[i - 1] && visited.count(i - 1) == 0)
            {
                continue;
            }
            
            visited.insert(i);
            
            ans.push_back(nums[i]);
            helper(nums, visited, ans, res);
            ans.pop_back();
            
            visited.erase(i);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        unordered_set<int> visited;
        vector<vector<int>> res;
        vector<int> ans;
        
        helper(nums, visited, ans, res);
        return res;       
    }
};