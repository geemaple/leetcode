// f(x) = f(left) + f(top)
// if obstacleGrid(left) == 1: f(left) = 0
// if obstacleGrid(top) == 1: f(top) = 0
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if (obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
        {
            return 1;
        }

        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> table(m, vector<int>(n, 0));

        for(auto i = 0; i < m; ++i)
        {
            for(auto j = 0; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    table[i][j] = 0;
                    continue;
                }

                if (i == 0 && j == 0)
                {
                    table[i][j] = 1 - obstacleGrid[i][j];
                }
                else
                {
                    if (i - 1 >= 0)
                    {
                        table[i][j] += table[i - 1][j];
                    }

                    if (j - 1 >= 0)
                    {
                        table[i][j] += table[i][j - 1];
                    }

                }
            }
        }

        return table[m - 1][n - 1];
    }
};
