// f[i] = min(f[j] + 1 where 0 <= j <= i - 1 and s[j: i - 1] is palindrome)
class Solution {
public:
    int minCut(string s) {
        if (s.size() == 0)
        {
            return 0;
        }

        int m = s.size();
        vector<vector<bool>>store(m, vector<bool>(m, false));
        // pre calculate
        int i, j = 0;
        for (auto t = 0; t < m; ++t)
        {
            // old palindrome
            i = j = t;
            while(i >= 0 && j < m && s[i] == s[j])
            {
                store[i][j] = true;
                i--;
                j++;
            }

            // even palindrome
            i = t;
            j = t + 1;
            while(i >= 0 && j < m && s[i] == s[j])
            {
                store[i][j] = true;
                i--;
                j++;
            }
        }

        vector<int> table(m + 1, 0);
        for(auto i = 1; i <= m; ++i)
        {
            int value = INT_MAX;
            for(auto j = 0; j < i; ++j)
            {
                if (store[j][i - 1])
                {
                    value = min(value, table[j] + 1);
                }
            }
            table[i] = value;
        }

        return table[m] - 1;
    }
};
