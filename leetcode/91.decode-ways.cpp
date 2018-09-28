// f(x) = f(x - 1) + f(x - 2)
// if x != 0: f(x - 1) is valid
// if 10 <= (x - 1)* 10 + x <= 26: f(x-2) is valid

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        vector<int> table(size + 1, 0);
        
        table[0] = 1;
        for (auto i = 1; i <= size; ++i)
        {
            if (s[i - 1] != '0')
            {
                table[i] += table[i - 1];
            }
            
            if(i - 2 >= 0 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] - '0' <= 6)))
            {
                table[i] += table[i - 2];
            }
        }
        
        return table[size];
    }
};
