// f(n) = min(f[n - j^2] + 1 where 1 <= j^2 <= n)
class Solution {
public:
    int numSquares(int n) {
        
        vector<int> table(n + 1, 0);

        for(auto i = 1; i <= n; ++i)
        {
            int value = INT_MAX;
            for(auto j = 1; j * j <= i; ++j)
            {
                value = min(value, table[i - j * j] + 1);
            }

            table[i] = value;
        }

        return table[n];
    }
};
