class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
        unordered_map<char, int> count_map;
        int j = 0;
        int res = 0;
        int k = 2;
        
        for (int i = 0; i < s.size(); ++i)
        {
            while(j < s.size() && (count_map.size() < k || (count_map.count(s[j]) > 0 && count_map.size() == k)))
            {
                count_map[s[j]] += 1;
                j ++;
            }
            
            res = max(res, j - i);
         
            if (count_map.count(s[i]) > 0){
                count_map[s[i]] -= 1;
                if (count_map[s[i]] == 0)
                {
                    count_map.erase(s[i]);
                }
            }
        }
        
        return res;
    }
};
