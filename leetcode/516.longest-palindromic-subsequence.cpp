// f[i][j] = max(f[i - 1][j], f[i][j - 1]) where s[i] != s[j])
// f[i][j] = f[i + 1][j - 1] + 2) where s[i] == s[j]
class Solution {
public:
    int longestPalindromeSubseq(string s) {

        if (s.size() == 0)
        {
            return 0;
        }

        int m = s.size();
        vector<vector<int>> table(m, vector<int>(m, -1));

        // length = 1
        for (auto i = 0; i < m; ++i)
        {
            table[i][i] = 1;
        }

        // length = 2
        for (auto i = 0; i < m - 1; ++i)
        {
            table[i][i + 1] = s[i] == s[i + 1] ? 2: 1; 
        }

        for(auto len = 3; len <= m; ++len)
        {
            for(auto i = 0; i <= m - len; ++i)
            {
                int j = i + len - 1;

                if (s[i] == s[j])
                {
                    table[i][j] = table[i + 1][j - 1] + 2;
                }
                else
                {
                    table[i][j] = max(table[i][j - 1], table[i + 1][j]);
                }
            }
        }

        return table[0][m - 1];
    }
};
