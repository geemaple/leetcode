class Solution {
private:
    void dfs(vector<int>& nums, int start, vector<int>& ans, vector<vector<int>>& results)
    {
        results.push_back(ans);

        for (auto i = start; i < nums.size(); ++i)
        {
            if (i != start && nums[i] == nums[i - 1])
            {
                continue;
            }

            ans.push_back(nums[i]);
            dfs(nums, i + 1, ans, results);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return vector<vector<int>>(1, vector<int>());
        }

        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        vector<int> ans;

        dfs(nums, 0, ans, results);

        return results;
    }
};
