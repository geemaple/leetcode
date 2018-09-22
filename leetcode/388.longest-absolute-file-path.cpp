class Solution {
private:
    vector<string> split(string& line, char seporator)
    {
        vector<string> res;
        string word = "";
        
        for(auto i = 0; i < line.size(); ++i)
        {
            if (line[i] == seporator)
            {
                res.push_back(word);
                word = "";
            }
            else
            {
                word += line[i];
            }
        }
        
        if (word.size() > 0)
        {
            res.push_back(word);
        }
        
        return res;
    }
public:
    int lengthLongestPath(string input) {
        vector<string> lines = split(input, '\n');
        unordered_map<int, int> table;
        int longest = 0;
        
        for (auto i = 0; i < lines.size(); ++i)
        {
            string l = lines[i];
            int level = l.find_last_of('\t') + 1;
            int size = l.substr(level).size();
            
            if (l.find('.') == -1)
            {
                table[level] = table[level - 1] + size + 1; // append len of "/" at the end
            }
            else
            {
                longest = max(longest, table[level - 1] + size);
            }
        }
        
        return longest;
    }
};