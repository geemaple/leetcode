// S1 start from i len k
// S2 start from j len k
// f[i][j][k] = (f[i][j][w] and f[i + w][j + w][k - w]) where 1 <= w <= k - 1
//              or (f[i][j + k - w][w] and f[i + w][j][k - w]) where 1 <= w <= k - 1


class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.size() != s2.size())
        {
            return false;
        }
        int m = s1.size();
        vector<vector<vector<bool>>> table(m, vector<vector<bool>>(m, vector<bool>(m + 1, false)));
        
        // len = 1
        for (auto i = 0; i < m; ++i)
        {
            for (auto j = 0; j < m; ++j)
            {
                table[i][j][1] = (s1[i] == s2[j]);
            }
        }
        
        for (auto k = 2; k <= m; ++k)
        {
            for (auto i = 0; i <= m - k; ++i)
            {
                for (auto j = 0; j <= m - k; ++j)
                {
                    for(auto w = 1; w <= k - 1; ++w)
                    {
                        // case 1
                        if (table[i][j][w] && table[i + w][j + w][k - w])
                        {
                            table[i][j][k] = true;
                            break;
                        }
                        
                        // case 2
                        if (table[i][j + k - w][w] && table[i + w][j][k - w])
                        {
                            table[i][j][k] = true;
                            break;
                        }
                    }
                }
            }
        }
        
        return table[0][0][m];
    }
};
