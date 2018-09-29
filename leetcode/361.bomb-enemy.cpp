// if grid[x] = 'E': f(x) = f(up) + 1
// if grid[x] = 'W': f(x) = 0
// if grid[x] = '0': f(x) = f(up)

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0)
        {
            return 0;
        }
        
        int m = (int)(grid.size());
        int n = (int)(grid[0].size());
        
        vector<vector<int>> direction(m, vector<int>(n, 0));
        vector<vector<int>> table(m, vector<int>(n, 0));
        
        // up
        for(auto i = 0; i < m; ++i)
        {
            for(auto j = 0; j < n; ++j)
            {
                if(i == 0)
                {
                    direction[0][j] = grid[0][j] == 'E' ? 1 : 0;
                }
                else
                {
                    if (grid[i][j] == 'E')
                    {
                        direction[i][j] = direction[i - 1][j] + 1;
                    }
                    else if (grid[i][j] == '0')
                    {
                        direction[i][j] = direction[i - 1][j];
                    }
                    else
                    {
                        direction[i][j] = 0;
                    }
                }
                
                table[i][j] += direction[i][j];
            }
        }
        
        // left
        for(auto i = 0; i < m; ++i)
        {
            for(auto j = 0; j < n; ++j)
            {
                if(j == 0)
                {
                    direction[i][0] = grid[i][0] == 'E' ? 1 : 0;
                }
                else
                {
                    if (grid[i][j] == 'E')
                    {
                        direction[i][j] = direction[i][j - 1] + 1;
                    }
                    else if (grid[i][j] == '0')
                    {
                        direction[i][j] = direction[i][j - 1];
                    }
                    else
                    {
                        direction[i][j] = 0;
                    }
                }
                
                table[i][j] += direction[i][j];
            }
        }
        
        // bottom
        for (auto i = m - 1; i >= 0; --i)
        {
            for(auto j = n - 1; j >=0; --j)
            {
                if(i == m - 1)
                {
                    direction[m - 1][j] = grid[m - 1][j] == 'E' ? 1 : 0;
                }
                else
                {
                    if (grid[i][j] == 'E')
                    {
                        direction[i][j] = direction[i + 1][j] + 1;
                    }
                    else if (grid[i][j] == '0')
                    {
                        direction[i][j] = direction[i + 1][j];
                    }
                    else
                    {
                        direction[i][j] = 0;
                    }
                }
                
                table[i][j] += direction[i][j];
            }
        }
        
        // right
        for (auto i = m - 1; i >= 0; --i)
        {
            for(auto j = n - 1; j >=0; --j)
            {
                if(j == n - 1)
                {
                    direction[i][n - 1] = grid[i][n - 1] == 'E' ? 1 : 0;
                }
                else
                {
                    if (grid[i][j] == 'E')
                    {
                        direction[i][j] = direction[i][j + 1] + 1;
                    }
                    else if (grid[i][j] == '0')
                    {
                        direction[i][j] = direction[i][j + 1];
                    }
                    else
                    {
                        direction[i][j] = 0;
                    }
                }
                
                table[i][j] += direction[i][j];
            }
        }
        
        int res = 0;
        for(auto i = 0; i < m; ++i)
        {
            for(auto j = 0; j < n; ++j)
            {
                if (grid[i][j] == '0')
                {
                    res = max(res, table[i][j]);
                }
            }
        }
        
        return res;
    }
};