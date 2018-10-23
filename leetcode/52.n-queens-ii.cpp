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
    
    void helper(int n, vector<int>& ans, vector<vector<int>>& res)
    {
        if (ans.size() == n)
        {
            res.push_back(ans);
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
    int totalNQueens(int n) {
        if (n <= 0)
        {
            return 0;
        }
        
        vector<vector<int>> res;
        vector<int> ans;
        
        helper(n, ans, res);
        return res.size();
    }
};