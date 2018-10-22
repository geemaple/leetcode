class Solution {
private:
    void helper(vector<int>& nums, int start, vector<int> &ans, vector<vector<int>>& res)
    {
        res.push_back(ans);
        
        for (auto i = start; i < nums.size(); ++i)
        {
            if (i != start && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            ans.push_back(nums[i]);
            helper(nums, i + 1, ans, res);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        
        helper(nums, 0, ans, res);
        return res;
    }
};