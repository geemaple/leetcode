class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        vector<int> mapS(256, 0);
        vector<int> mapT(256, 0);
    
        for (auto i = 0; i < s.size(); ++i){
            
            if (mapS[s[i]] != 0 && mapS[s[i]] != t[i]) {
                return false;
            }
            
            if (mapT[t[i]] != 0 && mapT[t[i]] != s[i]) {
                return false;
            }
         
            mapS[s[i]] = t[i];
            mapT[t[i]] = s[i];
        }
        
        return true;
    }
};
