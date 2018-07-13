class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int cur = 0;
        int furthest = 0;
        
        for (auto i = 0; i < nums.size() - 1; ++i)
        {
            furthest = max(furthest, i + nums[i]);
            if (i == cur)
            {
                if (furthest > i)
                {
                    cur = furthest;
                }
                else
                {
                    return false;
                }
            }
        }
        
        return furthest >= nums.size() - 1;
    }
};
