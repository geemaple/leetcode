//  Tag: Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
//   
//  Example 1:
//  
//  
//  Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//  Output: 6
//  Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
//  
//  Example 2:
//  
//  Input: height = [4,2,0,3,2,5]
//  Output: 9
//  
//   
//  Constraints:
//  
//  n == height.length
//  1 <= n <= 2 * 104
//  0 <= height[i] <= 105
//  
//  

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        for (int i = 1; i < n; i ++) {
            left[i] = max(left[i - 1], height[i - 1]);
        }

        for (int i = n - 2; i >= 0 ; i--) {
            right[i] = max(right[i + 1], height[i + 1]);
        }

        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            int h = min(left[i], right[i]);
            if (h > height[i]) {
                res += h - height[i];
            }
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int left_max = height[l];
        int right_max = height[r];

        int res = 0;
        while (l <= r) {
            if (left_max <= right_max) {
                res += max(0, left_max - height[l]);
                left_max = max(left_max, height[l]);
                l += 1;
            } else {
                res += max(0, right_max - height[r]);
                right_max = max(right_max, height[r]);
                r -= 1;
            }
        }
        return res;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int cur = st.top();
                st.pop();
                if (!st.empty()) {
                    int w = i - st.top() - 1;
                    int h = min(height[i], height[st.top()]) - height[cur];
                    res += w * h;
                }
            }
            st.push(i);
        }
        return res;
    }
};