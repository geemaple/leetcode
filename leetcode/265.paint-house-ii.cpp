// optimize version of Solution2
// find two smallest k1, k2 where k1 < k2 in table[pre]
// table[pre][k1] + diff_color_cost = k2 + diff_color_cost
// table[pre][other] + diff_color_cost = k1 + diff_color_cost
// O(M * N)
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
            int min1 = INT_MAX;
            int min2 = INT_MAX;
            
            for(auto j = 0; j < n; ++j)
            {
                if (table[i - 1][j] <= min1)
                {
                    min2 = min1;
                    min1 = table[i - 1][j];
                }
                else if(table[i - 1][j] < min2)
                {
                    min2 = table[i - 1][j];
                }
            }
            
            for(auto j = 0; j < n; ++j)
            {
                int val = (n > 1 && table[i - 1][j] == min1) ? min2: min1;
                table[i][j] = val + costs[i - 1][j];
            }
        }
        
        return *min_element(table[m].begin(), table[m].end());
    }
};

// f(x) = k-1 of min(f(x - 1) + diff_color_cost)
// f(0) = k of (f(0) + cost[0][k])
// O(M * N * N)
class Solution2 {
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
