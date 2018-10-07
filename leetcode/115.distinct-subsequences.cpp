// f[i][j] = f[i - 1][j] + f[i - 1][j - 1] where s[i - 1] == t[j - 1]
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));

        for (auto i = 0; i <= m; ++i)
        {
            for (auto j = 0; j <= n; ++j)
            {
                if (i == 0 || j == 0)
                {
                    table[i][j] = (j == 0) ? 1: 0;
                }
                else
                {
                    table[i][j] = table[i - 1][j];

                    if (s[i - 1] == t[j - 1])
                    {
                        table[i][j] += table[i - 1][j - 1];
                    }
                }
            }

        }

        return table[m][n];
    }
};
