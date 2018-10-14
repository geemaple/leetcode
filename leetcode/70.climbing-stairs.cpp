// f[i] = f[i - 1] + f[i - 2]
class Solution {
public:
    int climbStairs(int n) {
        
        vector<int> table(3, 0);
        table[0] = 1;
        table[1] = 1;
        
        for(auto i = 2; i <= n; ++i)
        {
            table[i % 3] = table[(i - 1 + 3) % 3] + table[(i - 2 + 3) % 3];
        }
        
        return table[n % 3];
    }
};

class Solution2 {
public:
    int climbStairs(int n) {
        
        vector<int> table(n + 1, 0);
        table[0] = 1;
        table[1] = 1;
        for (auto i = 2; i <= n; ++i) {
            table[i] = table[i - 1] + table[i - 2];
        }
        
        return table[n];
    }
};
