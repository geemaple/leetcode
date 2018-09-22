class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        
        string res;
        for (auto i = 0; i < strs.size(); ++i)
        {
            for(auto j = 0; j < strs[i].size(); ++j)
            {
                if (strs[i][j] == '|')
                {
                    res += "||";
                }
                else
                {
                    res += strs[i][j];
                }
            }

            res += "|+";
        }

        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        
        vector<string> res;
        string word = "";
        for (auto i = 0; i < s.size(); ++i)
        {
            if (s[i] == '|')
            {
                if (s[i + 1] == '+')
                {
                    res.push_back(word);
                    word = "";
                }
                else
                {
                    word += s[i + 1];
                }
                i++;
            }
            else
            {
                word += s[i];
            }
        }

        if (word.size() > 0)
        {
            res.push_back(word);
        }

        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
