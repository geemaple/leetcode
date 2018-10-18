class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> matching;
        matching['}'] = '{';
        matching[')'] = '(';
        matching[']'] = '[';
        
        stack<char> st;
        
        for (auto c: s)
        {
            if (matching.count(c) == 0)
            {
                st.push(c);
            }
            else
            {
                if (st.empty() || matching[c] != st.top())
                {
                    return false;
                }
                st.pop();
            }
        }
        
        return st.empty();   
    }
};