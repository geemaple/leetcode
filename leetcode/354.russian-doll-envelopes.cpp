class Solution {
private:
    static bool compare(pair<int, int> left, pair<int, int> right){
        return left.first < right.first;
    }
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        
        if (envelopes.size() == 0)
        {
            return 0;
        }
        
        sort(envelopes.begin(), envelopes.end(), compare);
        vector<int> table;
        table.push_back(1);
        
        for (auto i = 1; i < envelopes.size(); ++i)
        {
            int count = 1;
            for (auto j = 0; j < table.size(); ++j)
            {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second && count < table[j] + 1)
                {
                    count = table[j] + 1;
                }
            }
            
            table.push_back(count);
        }
        
        return *max_element(table.begin(), table.end());
    }
};
