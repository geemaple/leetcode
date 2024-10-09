#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        for (int i = 0; i < n; i++) {
            buildings.push_back({buildings[i][1], 0, 0});
        }

        sort(buildings.begin(), buildings.end());
        vector<vector<int>> res;
        priority_queue<pair<int, int>> heap;
        for (int i = 0; i < buildings.size(); i++) {
            vector<int> tuple = buildings[i];
            int l = tuple[0], r = tuple[1], h = tuple[2];
            while (!heap.empty() && heap.top().second <= l) {
                heap.pop();
            }

            if (h > 0) {
                heap.push(make_pair(h, r));
            }
            
            if (i == buildings.size() - 1 || buildings[i][0] != buildings[i + 1][0]) {
                int height = heap.empty() ? 0 : heap.top().first;
                if (res.size() == 0 || height != res.back()[1]) {
//                    res.push_back({i, height});
                    res.emplace_back(vector<int>{l, height});
                }
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> graph= {{2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8}};
    
    vector<int> nums1 = {-3,-1,2,4,5};
    vector<int> nums2 = {-3,-1,2,4,5};
    Solution s;
    vector<vector<int>> res = s.getSkyline(graph);
//    cout << res << endl;
//    for (int word : res) {
//        cout << std::to_string(word) << ", ";
//    }
//    cout << endl;
    
    return 0;
}

