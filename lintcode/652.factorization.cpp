class Solution {
private:
    void dfs(int start, int remain, vector<int> &ans, vector<vector<int>> &res)
    {
        if (ans.size() > 0)
        {
            ans.push_back(remain);
            res.push_back(ans);
            ans.pop_back();
        }
        
        for(auto i = start; i < remain; ++i)
        {
            
            if (remain / i < i)
            {
                break;
            }
            
            if (remain % i == 0)
            {
                ans.push_back(i);
                
                dfs(i, remain / i, ans, res);
                
                ans.pop_back();
            }
        }
    }
public:
    /**
     * @param n: An integer
     * @return: a list of combination
     */
    vector<vector<int>> getFactors(int n) {
        // write your code here
        vector<vector<int>> res;
        vector<int> ans;
        dfs(2, n, ans, res);
        return res;
    }
};