// f[cost][color1] = min(f[cost - 1][color2] + costs[color1], f[cost - 1][color3] + costs[color1])
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        
        if (costs.size() == 0)
        {
            return 0;
        }
        
        int size = costs.size();
        int color_size = costs[0].size();
        vector<vector<int>> table(size + 1, vector<int>(color_size, 0)); // costs
        
        for (auto i = 1; i <= size; ++i)
        {
            for(auto j = 0; j < color_size; ++j) //const 3
            {
                int cost = INT_MAX;
                for(auto p = 0; p < color_size; ++p) //const 2
                {
                    if (p != j)
                    {
                        cost = min(cost, table[i - 1][p] + costs[i - 1][j]);
                    }
                }
                table[i][j] = cost;
            }
        }
        
        int ans = INT_MAX;
        for (auto total: table[size])
        {
            ans = min(ans, total);
        }
        return ans;
    }
};