// f[i] = (k - 1) * f[i - 1] + (k - 1) * f[i - 2]

class Solution {
public:
    int numWays(int n, int k) {

        if (n == 0 || k == 0)
        {
            return 0;
        }

        if (n == 1)
        {
            return k;
        }

        vector<int> table(n + 1, 0);
        
        table[1] = k;
        table[2] = k * k;
        
        for (auto i = 3; i <= n; ++i)
        {
            table[i] = (k - 1) * table[i - 1] + (k - 1) * table[i - 2];
        }
        
        return table[n];
        
    }
};


class Solution2 {
public:
    int numWays(int n, int k) {
        
        if (n == 0 || k == 0)
        {
            return 0;
        }

        if (n == 1)
        {
            return k;
        }
        
        int same = k;
        int diff = k * (k - 1);
        
        for (auto i = 3; i <= n; ++i)
        {
            int tmp = diff;
            diff = (same + diff) * (k - 1);
            same = tmp;
        }
        
        return same + diff;
    }
};
