#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
using namespace std;

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
                    int distance = i - st.top() - 1;
                    int h = min(height[i], height[st.top()]) - height[cur];
                    res += distance * h;
                }
            }
            st.push(i);
        }
        return res;
    }
};


int main() {
    vector<int> graph= {0,1,0,2,1,0,1,3,2,1,2,1};
    
    vector<int> nums1 = {-3,-1,2,4,5};
    vector<int> nums2 = {-3,-1,2,4,5};
    Solution s;
    int res = s.trap(graph);
    cout << res << endl;
//    for (auto word : res) {
//        cout << word << ", ";
//    }
    cout << endl;
    
    return 0;
}

