class Solution {
public:
    string minWindow(string s, string t) {
        
        if (s.size() < t.size()){
            return "";
        }
        
        unordered_map<char, int> map;
        int missing = t.size();
        
        for (auto i = 0; i < t.size(); ++i) {
            map[t[i]] += 1;
        }
        
        pair<int, int> res = make_pair(1, INT_MAX);
        
        int start = 0;
        for (auto end = 0; end < s.size(); ++end){
            
            if (map.count(s[end]) > 0){
                if (map[s[end]] > 0) {
                    missing -= 1;
                }
                map[s[end]] -= 1;
            }
            
            while (missing == 0){
                if (res.second - res.first > end + 1 - start){
                    res = make_pair(start, end + 1);
                }
                
                // remove start
                if (map.count(s[start]) > 0) {
                    if (map[s[start]] == 0) {
                        missing += 1;
                    }
                    map[s[start]] += 1;
                }
                start += 1;
            }
        }
        
        return (res.second != INT_MAX)? s.substr(res.first, res.second - res.first): "";
    }
};
