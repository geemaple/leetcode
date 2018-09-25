class Solution {
    
private:
    unordered_map<char, vector<char>> mapping;
    void dfs(int level, string &answer, string &digits, vector<string> &res)
    {
        if (level == digits.size())
        {
            res.push_back(answer);
            return;
        }
        
        char number = digits[level];
        for (auto i = 0; i < mapping[number].size(); ++i)
        {
            answer += mapping[number][i];
            dfs(level + 1, answer, digits, res);
            answer.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
        {
            return vector<string>();
        }
        
        vector<string> res;
        string answer = "";
        
        mapping['2'] = {'a', 'b', 'c'};
        mapping['3'] = {'d', 'e', 'f'};
        mapping['4'] = {'g', 'h', 'i'};
        mapping['5'] = {'j', 'k', 'l'};
        mapping['6'] = {'m', 'n', 'o'};
        mapping['7'] = {'p', 'q', 'r', 's'};
        mapping['8'] = {'t', 'u', 'v'};
        mapping['9'] = {'w', 'x', 'y', 'z'};
        
        dfs(0, answer, digits, res);
        
        return res;
    }
};