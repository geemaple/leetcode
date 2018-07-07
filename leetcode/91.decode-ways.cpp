class Solution {
public:
    int numDecodings(string s) {
        
        if (s.size() == 0) {
            return 0;
        }
        
        vector<int> table(s.size() + 1, 0);
        table[0] = (s[0] != '0') ? 1 : 0;
        
        for (auto i = 1; i <= s.size(); i++) {
            if (s[i - 1] != '0') {
                table[i] += table[i - 1];
            }
            
            // number in range [10, 26]
            if (i - 2 >= 0 && s[i - 2] != '0' && (s[i - 2] - '0') * 10 + s[i - 1] - '0' <= 26) {
                table[i] += table[i - 2];
            }
        }
        
        return table[table.size() - 1];
    }
};
