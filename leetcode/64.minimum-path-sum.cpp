// f(x) = min(num[x] + f(left), num[x] + f(top))
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0)
        {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> table(m, vector<int>(n, 0));

        for (auto j = 0; j < n; ++j)
        {
            table[0][j] = grid[0][j];
            if (j - 1 >= 0)
            {
                table[0][j] += table[0][j - 1];
            }
        }

        for(auto i = 1; i < table.size(); ++i)
        {
            for(auto j = 0; j < table[i].size(); ++j)
            {

                int value = table[i - 1][j] + grid[i][j];

                if (j - 1 >= 0)
                {
                    value = min(value, table[i][j - 1] + grid[i][j]);
                }

                table[i][j] = value;
            }
        }

        return table[m - 1][n - 1];

    }
};
