class Solution {
    
private:
    int target;
    string num;
    void dfs(int pos, long last, long sum, string path, vector<string>& res){
        
        if (pos == num.size())
        {
            if (sum == target)
            {
                res.push_back(path);
            }
            
            return;
        }
        
        long curVal = 0;
        string cur = "";
        for(auto i = pos; i < num.size(); ++i)
        {
            curVal = curVal * 10 + num[i] - '0';
            cur += num[i];
            
            if (pos == 0)
            {
                dfs(i + 1, curVal, curVal, path + cur, res);
            }
            else
            {
                dfs(i + 1, curVal, sum + curVal , path + "+" + cur, res);
                dfs(i + 1, -curVal, sum - curVal , path + "-" + cur, res);
                dfs(i + 1, curVal * last, sum - last + curVal * last , path + "*" + cur, res);
            }
            
            if (num[pos] == '0') {
                break;
            }
        }
    }
public:
    vector<string> addOperators(string num, int target) {
        if (num.size() == 0)
        {
            return vector<string>();
        }
        
        this->target = target;
        this->num = num;
        
        vector<string> res;
        dfs(0, 0, 0, "", res);
        return res;
    }
};