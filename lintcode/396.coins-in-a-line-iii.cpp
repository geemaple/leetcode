// f[i][j] = max(a[i] - f[i + 1][j], a[j] - f[i][j - 1])
class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        // write your code here

        if (values.size() == 0)
        {
            return true;
        }

        int m = values.size();
        vector<vector<int>> table(m, vector<int>(m, 0));

        //len = 1
        for(auto i = 0; i < m; ++i)
        {
            table[i][i] = values[i];
        }

        for(auto len = 2; len <= m; ++len)
        {
            for(auto i = 0; i <= m - len; ++i)
            {
                int j = i + len - 1;
                table[i][j] = max(values[i] - table[i + 1][j], values[j] - table[i][j - 1]);
            }
        }

        return table[0][m - 1];
    }
};