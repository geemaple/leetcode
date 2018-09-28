// f(x) = min(f(x - 1) + 1, f(x - 2) + 1, f(x - 5) + 1)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> table(amount + 1, INT_MAX);
        table[0] = 0;
        for(auto i = 1; i <= amount; ++i)
        {
            int ans = INT_MAX;
            for(auto j = 0; j < coins.size(); ++j)
            {
                int pre = i - coins[j];
                if (pre >= 0 && table[pre] != INT_MAX  && table[pre] + 1 < ans)
                {
                    ans = table[pre] + 1;
                }
            }
            table[i] = ans;
        }
        
        return table[amount] == INT_MAX ? -1 : table[amount];
    }
};