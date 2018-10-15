class Solution {
public:
    string decodeString(string s) {
        
    }
};
class Solution {
public:
    string decodeString(string s) {
        
        stack<char> st;
        for (auto i = 0; i < s.size(); ++i)
        {
            if (s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string chuck = "";
                while(st.top() != '[')
                {
                    chuck = st.top() + chuck;
                    st.pop();
                }
                
                st.pop();
                
                int count = 0;
                int unit = 1;
                while(!st.empty() && st.top() >= '0' && st.top() <= '9')
                {
                    count += (st.top() - '0') * unit;
                    st.pop();
                    unit *= 10;
                }
                
                for (auto i = 0; i < count; ++i)
                {
                    for(auto j = 0; j < chuck.size(); ++j)
                    {
                        st.push(chuck[j]);
                    }
                }
            }
        }
        
        string res;
        while(!st.empty())
        {
            res = st.top() + res;
            st.pop();
        }
        
        return res;
        
    }
};