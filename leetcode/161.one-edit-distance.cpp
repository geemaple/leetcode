class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        
        int diff = int(s.size()) - int(t.size());
        
        if (abs(diff) > 1)
        {
            return false;
        }
        
        if (abs(diff) == 0)
        {
            int count = 0;
            for(auto i = 0; i < s.size(); ++i)
            {
                if (s[i] != t[i])
                {
                    count ++;
                }
            }
            
            return count == 1;
        }
        
        if (abs(diff) == 1)
        {
            string small = diff > 0 ? t: s;
            string large = diff < 0 ? t: s;
            
            for(auto i = 0; i < small.size(); ++i)
            {
                if (small[i] != large[i])
                {
                    return small.substr(i, small.size() - i) == large.substr(i + 1, large.size() - i - 1);
                }
            }
        }
        
        return true;
    }
};