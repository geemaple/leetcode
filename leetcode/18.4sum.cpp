class Solution {
    void twoSum(vector<int>& nums, int first, int second, int target, vector<vector<int>> &result)
    {
        int start = second + 1;
        int end = nums.size() - 1;
        while (start < end) {
            
            int tmp = nums[first] + nums[second] + nums[start] + nums[end];
            if (tmp == target)
            {
                result.push_back(vector<int>{nums[first], nums[second], nums[start], nums[end]});
                
                while (start < end && nums[start + 1] == nums[start]) {
                    start += 1;
                }
                
                while (start < end && nums[end - 1] == nums[end]) {
                    end -= 1;
                }
                
                start += 1;
                end -= 1;
            }
            else if (tmp > target)
            {
                end -= 1;
            }
            else
            {
                start += 1;
            }
        }
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4)
        {
            vector<vector<int>>();
        }
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for (auto i = 0; i < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
            for (auto j = i + 1; j < nums.size(); ++j)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
                
                twoSum(nums, i, j, target, res);
            }
        }
        
        return res;
    }
};
