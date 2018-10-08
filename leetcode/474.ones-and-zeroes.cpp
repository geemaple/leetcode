// f[i][j][k] = max(f[i - 1][j][k], f[i - 1][j - count0[i - 1]][k - count1[i - 1]] + 1 where j >=S0 and k >= S1

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        int size = strs.size();
        vector<int> count0(size, 0);
        vector<int> count1(size, 0);
        
        for (auto i = 0; i < strs.size(); ++i)
        {
            for (auto j = 0; j < strs[i].size(); ++j)
            {
                if (strs[i][j] == '0')
                {
                    count0[i] += 1;
                }
                else
                {
                    count1[i] += 1;
                }
            }
        }
        
        vector<vector<vector<int>>> table(size + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        
        for (auto i = 1; i <= size; ++i)
        {
            for (auto j = 0; j <= m; ++j)
            {
                for (auto k = 0; k <= n; ++k)
                {
                    table[i][j][k] = table[i - 1][j][k];
                    
                    if (j >= count0[i - 1] && k >= count1[i - 1])
                    {
                        table[i][j][k] = max(table[i][j][k], table[i - 1][j - count0[i - 1]][k - count1[i - 1]] + 1);
                    }
                }
            }
        }
        
        return table[size][m][n];
    }
};