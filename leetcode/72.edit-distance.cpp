// f[i][j] = min(f[i][j - 1] + 1, f[i - 1][j - 1] + 1, f[i - 1][j] + 1, f[i - 1][j - 1] where s1[i - 1] == s2[j - 1])
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        
        for (auto i = 0; i <= m; ++i)
        {
            for (auto j = 0; j <= n; ++j)
            {
                if (i == 0 || j == 0)
                {
                    table[i][j] = abs(i - j);
                }
                else
                {
                    if (word1[i - 1] == word2[j - 1])
                    {
                        table[i][j] = table[i - 1][j - 1];
                    }
                    else
                    {
                        int value = min(table[i][j - 1] + 1, table[i - 1][j] + 1);
                        value = min(value, table[i - 1][j - 1] + 1);
                        table[i][j] = value;
                    }
                    
                }
            }
        }
        
        return table[m][n];
    }
};
