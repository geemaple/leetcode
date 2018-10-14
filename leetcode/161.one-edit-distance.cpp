class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        
        int size_s = (int)(s.size());
        int size_t = (int)(t.size());
        
        if (size_s == size_t) //replace
        {
            int diff = 0;
            for(auto i = 0; i < s.size(); ++i)
            {
                if (s[i] != t[i])
                {
                    if (++diff > 1)
                    {
                        break;
                    }
                }
            }
            
            return diff == 1;
        }
        
        if (abs(size_s - size_t) == 1) //delete or insert
        {
            string& small = size_s > size_t ? t: s;
            string& large = size_s < size_t ? t: s;
            int diff = 0;
       
            for (auto i = 0; i < large.size(); ++i)
            {
                if (i - diff >= small.size() || small[i - diff] != large[i])
                {
                    if (++diff > 1)
                    {
                        break;
                    }
                }
            }
            
            return diff == 1;
        }
        
        return false;
    }
};