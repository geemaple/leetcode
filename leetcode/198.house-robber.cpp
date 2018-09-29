// if steal x: f(x) = min(f(x - 1) + nums[x])
// if not steal x: = min(f(x - 1))
class Solution {
public:
    int rob(vector<int>& nums) {
        
        if (nums.size() == 0)
        {
            return 0;
        }

        int m = nums.size();
        vector<vector<int>> table(m + 1, vector<int>(2, 0));
        for(auto i = 1; i <= m; ++i)
        {
            // not steal
            table[i][0] = max(table[i - 1][0], table[i - 1][1]);

            // steal
            table[i][1] = table[i - 1][0] + nums[i - 1];
        }

        return *max_element(table[m].begin(), table[m].end());
    }
};
