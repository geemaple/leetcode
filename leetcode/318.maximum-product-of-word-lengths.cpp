class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        if (words.size() == 0)
        {
            return 0;
        }
        
        vector<int> mask(words.size(), 0);
        for (auto i = 0; i < words.size(); ++i)
        {
            for (auto c: words[i])
            {
                mask[i] |= 1 << (c - 'a');
            }
        }
        
        int res = 0;
        for (auto i = 0; i < words.size(); ++i)
        {
            for (auto j = i + 1; j < words.size(); ++j)
            {
                if ((mask[i] & mask[j]) == 0 && words[i].size() * words[j].size() > res)
                {
                    res = words[i].size() * words[j].size();
                }
            }
        }
        
        return res;
    }
};