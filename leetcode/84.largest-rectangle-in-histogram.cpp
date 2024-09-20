//  Tag: Array, Stack, Monotonic Stack
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
//   
//  Example 1:
//  
//  
//  Input: heights = [2,1,5,6,2,3]
//  Output: 10
//  Explanation: The above is a histogram where width of each bar is 1.
//  The largest rectangle is shown in the red area, which has an area = 10 units.
//  
//  Example 2:
//  
//  
//  Input: heights = [2,4]
//  Output: 4
//  
//   
//  Constraints:
//  
//  1 <= heights.length <= 105
//  0 <= heights[i] <= 104
//  
//  

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);
        int n = heights.size();
        stack<int> st;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int index = st.top();
                st.pop();
                int left = st.empty() ? 0 : st.top() + 1;
                res = max(res, (i - left) * heights[index]);
            }

            st.push(i);
        }
        return res;
    }
};