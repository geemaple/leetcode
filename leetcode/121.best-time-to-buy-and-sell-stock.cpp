class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() == 0)
        {
            return 0;
        }

        int res = 0;
        int low = prices[0];

        for(auto i = 1; i < prices.size(); ++i)
        {
            res = max(res, prices[i] - low);
            low = min(low, prices[i]);
        }

        return res;
    }
};
