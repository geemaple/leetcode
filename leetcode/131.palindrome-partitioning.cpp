class Solution {
private:
    vector<vector<bool>> isPalindrome;
    
    void helper(string& s, int start, vector<string>& ans, vector<vector<string>>& res)
    {
        if (start == s.size())
        {
            res.push_back(ans);
            return;
        }
        
        for (auto i = start; i < s.size(); ++i)
        {
            if (isPalindrome[start][i])
            {
                ans.push_back(s.substr(start, i - start + 1));
                helper(s, i + 1, ans, res);
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int size = s.size();
        isPalindrome.resize(size, vector<bool>(size, false));
        
        int i, j =0;
        for (auto t = 0; t < size; ++t)
        {
            i = j = t;
            while(i >= 0 && j < size && s[i] == s[j])
            {
                isPalindrome[i][j] = true;
                i--;
                j++;
            }
            
            i = t;
            j = t + 1;
            while(i >= 0 && j < size && s[i] == s[j])
            {
                isPalindrome[i][j] = true;
                i--;
                j++;
            }
        }
        
        vector<string> ans;
        vector<vector<string>> res;
        helper(s, 0, ans, res);
        
        return res;
    }
};