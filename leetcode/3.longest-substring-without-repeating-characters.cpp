class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> set;
        int res = 0;
        int start = 0;
        int end = 0;
        for(; end < s.size(); ++end){
            
            if (set.count(s[end]) > 0){
                if (res < end - start){
                    res = end - start;
                }
                
                while(s[start] != s[end]){
                    set.erase(s[start]);
                    start += 1;
                }
                
                start += 1;
            }
            else
            {
                set.insert(s[end]);
            }
        }
        
        if (res < end - start){
            res = end - start;
        }
        
        return res;
    }
};