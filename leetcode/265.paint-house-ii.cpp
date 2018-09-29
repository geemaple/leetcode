// f(x) = min(f(x - 1) + diff_color_cost ...)
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.size() == 0)
        {
            return 0;
        }

        int m = costs.size();
        int n = costs[0].size();

        vector<vector<int>> table(m + 1, vector<int>(n, 0));

        for(auto i = 1; i <= m; ++i)
        {
            for(auto j = 0; j < n; ++j)
            {
                int val = INT_MAX;
                for(auto p = 0; p < n; ++p)
                {
                    if (i == 1 || j != p)
                    {
                        val = min(val, table[i - 1][p] + costs[i - 1][j]);
                    }
                } 

                table[i][j] = val;
            }
        }

        return *min_element(table[m].begin(), table[m].end());
    }
};
