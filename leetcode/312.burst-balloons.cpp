// f[i][j] = max(f[i][k] + f[k][j] + nums[i] * nums[k] * nums[j]) where i < k < j
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        
        vector<int> balloons(nums.size() + 2, 1);
        for (auto i = 0; i < nums.size(); ++i)
        {
            balloons[i + 1] = nums[i];
        }
        
        int m = balloons.size();
        vector<vector<int>> table(m, vector<int>(m, 0));
        
        // len = 2
        for (auto i = 0; i < m - 1; ++i)
        {
            table[i][i + 1] = 0;
        }
        
        for (auto len = 3; len <= m; ++len)
        {
            for (auto i = 0; i <= m - len; ++i)
            {
                int j = i + len - 1;
                for(auto k = i + 1; k <= j - 1; ++k)
                {
                    table[i][j] = max(table[i][j], table[i][k] + table[k][j] + balloons[i] * balloons[k] * balloons[j]);
                }
            }
        }
        
        return table[0][m - 1];
    }
};