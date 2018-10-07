// f[i][j] = (f[i - 1][j] and s1[i - 1] == S3[i + j - 1])
//      or = (f[i][j - 1] and s2[j - 1] == S3[i + j - 1])
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }

        int m = s1.size();
        int n = s2.size();

        vector<vector<bool>> table(m + 1, vector<bool>(n + 1, false));
        

        for (auto i = 0; i <= m; ++i)
        {
            for (auto j = 0; j <= n; ++j)
            {
                if (i == 0 && j == 0)
                {
                    table[0][0] = true;
                    continue;
                }
                else
                {
                    if (i > 0 && (table[i - 1][j] && s1[i - 1] == s3[i + j - 1]))
                    {
                        table[i][j] = true;
                    } 

                    if (j > 0 && (table[i][j - 1] && s2[j - 1] == s3[i + j - 1]))
                    {
                        table[i][j] = true;
                    }
                }
            }
        }

        return table[m][n];
    }
};
