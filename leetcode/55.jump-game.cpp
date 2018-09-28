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

// Dynamic programming
// table[i] = or (table[pre] >= i - pre)
// O(N ^ 2)
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        vector<bool>table(nums.size(), false);
        table[0] = true;
        
        for(auto i = 1; i < nums.size(); ++i)
        {
            for(auto j = 0; j < i; ++j)
            {
                if (table[j] && nums[j] >= i - j)
                {
                    table[i] = true;
                    break;
                }
            }
        }
        
        return table[nums.size() - 1];
        
    }
};
