class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        }
        
        vector<int> table(n + 1, 0);
        table[0] = 1;
        for (auto i = 1; i <= n; ++i) {
            //at ith stair
            if (i - 1 >= 0) {
                table[i] += table[i - 1];
            }
            
            if (i - 2 >= 0) {
                table[i] += table[i - 2];
            }
        }
        
        return table[table.size() - 1];
    }
};
