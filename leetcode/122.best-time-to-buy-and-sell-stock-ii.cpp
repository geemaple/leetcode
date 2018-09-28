class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
        {
            return 0;
        }

        int profit = 0;
        for (auto i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};
