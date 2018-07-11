class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        vector<int> res;
        int extra = 1;
        int count = (int)digits.size();
        
        for(int i = count - 1; i >= 0; --i)
        {
            res.push_back((digits[i] + extra) % 10);
            extra = (digits[i] + extra) / 10;
        }
        
        if (extra > 0)
        {
            res.push_back(extra);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};