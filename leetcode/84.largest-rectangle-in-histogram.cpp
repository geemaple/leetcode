class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        vector<int> nums(heights.begin(), heights.end());
        nums.push_back(-1);
        
        int res = 0;
        for (auto i = 0; i < nums.size(); ++i)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
            {
                int index = st.top();
                st.pop();
                
                int left = st.empty() ? -1 : st.top();
                int width = i - left + 1 - 2;
                res = max(res, nums[index] * width);
            }
            
            st.push(i);
        }
        
        return res;
    }
};