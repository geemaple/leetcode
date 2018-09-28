// f(target) = f(left) + f(top)
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> table(m, vector<int>(n, 0));

        for(auto i = 0; i < m; ++i)
        {
            for(auto j = 0; j < n; ++j)
            {
                if (i == 0 || j == 0)
                {
                    table[i][j] = 1;
                }
                else
                {
                    table[i][j] = table[i - 1][j] + table[i][j - 1];
                }
            }
        }

        return table[m - 1][n - 1];
    }
};
