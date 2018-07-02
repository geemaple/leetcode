class Solution {
private:
    void dfsTraversal(vector<int>& nums, vector<int> &tmp, int start, vector<vector<int>> &result){
        
        result.push_back(tmp);
        
        for (auto i = start; i < nums.size(); ++i)
        {
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }
            
            tmp.push_back(nums[i]);
            dfsTraversal(nums, tmp, i + 1, result);
            tmp.pop_back();
        }
    }
    
public:
    // DFS
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        if (nums.size() == 0)
        {
            return vector<vector<int>>();
        }
        
        sort(nums.begin(), nums.end());
        
        vector<int> tmp;
        vector<vector<int>> result;
        
        dfsTraversal(nums, tmp, 0, result);
        
        return result;
    }
};
