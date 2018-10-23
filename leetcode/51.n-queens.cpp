class Solution {
    
private:
    
    bool no_attack(vector<int>& ans, int y)
    {
        if (ans.size() == 0)
        {
            return true;
        }
        
        int x = ans.size();
        
        for (auto i = 0; i < ans.size(); ++i)
        {
            int test_x = i;
            int test_y = ans[i];
            
            if (y == test_y || x + y == test_x + test_y || x - y == test_x - test_y)
            {
                return false;
            }
        }
        
        return true;
    }
    
    vector<string> draw(vector<int>& ans)
    {
        vector<string> res;
        for (auto i = 0; i < ans.size(); ++i)
        {
            string line(ans.size(), '.');
            line[ans[i]] = 'Q';
            res.push_back(line);
        }
        
        return res;
    }
    
    void helper(int n, vector<int>& ans, vector<vector<string>>& res)
    {
        if (ans.size() == n)
        {
            res.push_back(draw(ans));
            return;
        }
        
        for (auto i = 0; i < n; ++i)
        {
            if (no_attack(ans, i))
            {
                ans.push_back(i);
                helper(n, ans, res);
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0)
        {
            return vector<vector<string>>();
        }
        
        vector<vector<string>> res;
        vector<int> ans;
        
        helper(n, ans, res);
        return res;
    }
};