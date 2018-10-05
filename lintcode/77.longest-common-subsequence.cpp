// f[i][j] = max(f[i - 1][j], f[i][j - 1], f[i - 1][j - 1] + 1 where A[i - 1] == B[j - 1])
class Solution {
public:
    /**
     * @param A: A string
     * @param B: A string
     * @return: The length of longest common subsequence of A and B
     */
    int longestCommonSubsequence(string &A, string &B) {
        // write your code here

        if (A.size() == 0 || B.size() == 0)
        {
            return 0;
        }

        int m  = A.size();
        int n = B.size();

        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        for (auto i = 0; i <= m; ++i)
        {
            for (auto j = 0; j <= n; ++j)
            {
                if (i == 0 || j == 0)
                {
                    table[i][j] = 0;
                    continue;
                }

                table[i][j] = max(table[i - 1][j], table[i][j - 1]);

                if (A[i - 1] == B[j - 1])
                {
                    table[i][j] = table[i - 1][j - 1] + 1;
                }
            }
        }

        return table[m][n];
    }
};