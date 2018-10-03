// f[i] = f[i - A1] + f[i - A2] ... + f[i - A(n-1)]
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> table(target + 1, 0);
        table[0] = 1;

        for(auto i = 1; i <= target; ++i)
        {
            int count = 0;

            for (auto j = 0; j < nums.size(); ++j)
            {
                if (i - nums[j] >= 0)
                {
                    count += table[i - nums[j]];
                }
            }

            table[i] = count;
        }

        return table[target];
    }
};
