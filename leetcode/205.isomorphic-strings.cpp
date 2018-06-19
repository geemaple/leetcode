class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char, char> map_s;
        unordered_map<char, char> map_t;
        for (auto i = 0; i < s.size(); ++i){
                        
            char char_s = s[i];
            char char_t = t[i];
            
            if (map_s.count(char_s) > 0 && map_s[char_s] != char_t){
                return false;
            }
            
            if (map_t.count(char_t) > 0 && map_t[char_t] != char_s){
                return false;
            }
            
            map_s.insert(make_pair(char_s, char_t));
            map_t.insert(make_pair(char_t, char_s));
        }
        
        return true;
    }
};