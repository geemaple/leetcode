#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> max_heap; // <高度, 右端>
        int i = 0, len = buildings.size();
        int cur_x, cur_h;

        while (i < len || !max_heap.empty()) {
            if (max_heap.empty() || (i < len && buildings[i][0] <= max_heap.top().second)) {
                // 处理所有左端点在当前横坐标
                cur_x = buildings[i][0];
                while (i < len && cur_x == buildings[i][0]) {
                    max_heap.emplace(buildings[i][2], buildings[i][1]);
                    ++i;
                }
            } else {
                // 处理所有右端点
                cur_x = max_heap.top().second;
                while (!max_heap.empty() && cur_x >= max_heap.top().second) {
                    max_heap.pop();
                }
            }
            
            cur_h = (max_heap.empty()) ? 0 : max_heap.top().first;
            if (ans.empty() || cur_h != ans.back()[1]) {
                ans.push_back({cur_x, cur_h});
            }
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    
    vector<vector<int>> res = s.getSkyline(grid);
    for (auto x: res) {
        cout << "(" << x[0] << "," << x[1] << ") ";
    }
    cout << endl;
}
