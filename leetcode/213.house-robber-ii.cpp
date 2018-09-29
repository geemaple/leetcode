class Solution {
private:
    int robHouse(vector<int>& nums, int start, int end)
    {
        if (end - start + 1 <= 0)
        {
            return 0;
        }
        
        int m = end - start  + 1;
        vector<int> table(m + 1, 0);
        table[1] = nums[start];
        
        for(auto i = 2; i <= m; ++i)
        {
            table[i] = max(table[i - 2] + nums[start + i - 1], table[i - 1]);
        }
        
        return table[m];
    }
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 0)
        {
            return 0;
        }
        
        return max(robHouse(nums, 1, nums.size() - 1), nums[0] + robHouse(nums, 2, nums.size() - 2));
    }
};