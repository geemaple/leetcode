class Solution {
    
private:
    int maximaArea(vector<int>& nums)
    {
        nums[nums.size() - 1] = -1;
        stack<int> st;
        
        int res = 0;
        for (auto i = 0; i < nums.size(); ++i)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                int index = st.top();
                st.pop();
                
                int left = st.empty() ? -1 : st.top();
                int width = i - left + 1 - 2;
                res = max(res, width * nums[index]);
            }
            
            st.push(i);
        }
        
        return res;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return 0;
        }
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> nums(n + 1, 0);
        int res = 0;
        
        for (auto i = 0; i < m; ++i)
        {
            for (auto j = 0; j < n; ++j)
            {
                if (matrix[i][j] == '1')
                {
                    nums[j] += 1;
                }
                else
                {
                    nums[j] = 0;
                }
            }
            
            res = max(res, maximaArea(nums));
        }
        
        return res;
    }
};