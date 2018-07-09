class Solution {
public:
    int jump(vector<int>& nums) {
        
        int cur_end = 0;
        int cur_farthest = 0;
        int jumps = 0;
        
        for (auto i = 0; i < nums.size() - 1; ++i)
        {
            cur_farthest = max(cur_farthest, i + nums[i]);
            
            if (i == cur_end)
            {
                cur_end = cur_farthest;
                jumps += 1;
            }
        }
        
        return jumps;
    }
};

class Solution2 {
public:
    int jump(vector<int>& nums) {
        vector<int> table(nums.size(), 0);
        
        for (auto i = 1; i < nums.size(); ++i)
        {
            int step = INT_MAX;
            for (auto j = 0; j < i; ++j)
            {
                if (i - j <= nums[j])
                {
                    step = min(step, table[j] + 1);
                }
            }
            table[i] = step;
        }
        
        return table[nums.size() - 1];
    }
};
