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
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        int directions[5] = {-1, 0, 1, 0, -1};
        unordered_set<int> visited;
        priority_queue<tuple<int, int, int>> heap;
        heap.emplace(health, 0, 0);

        while (!heap.empty()) {
            auto [left, i, j] = heap.top();
            heap.pop();
            if (left == 0) {
                return false;
            }

            if (i == n - 1 && j == m - 1) {
                cout << i << "," << j << endl;
                return true;
            }

            if (visited.count(i * m + j) > 0) {
                continue;
            }
            visited.insert(i * m + j);
            for (int d = 0; d < 4; d++) {
                int x = i + directions[d];
                int y = j + directions[d + 1];
                if (x >= 0 && x < n && y >= 0 && y < m && visited.count(x * m + y) == 0) {
                    cout << left - grid[x][y] << "," << x << "," << y << endl;
                    heap.emplace(left - grid[x][y], x, y);
                }
            }
        }

        return false;
    }
};


int main() {
    vector<vector<int>> matrix = {
        {0,1,1,0,0,0},
        {1,0,1,0,0,0},
        {0,1,1,1,0,1},
        {0,0,1,0,1,0}
    };
    
    vector<int> nums1 = {-3,-1,2,4,5};
    vector<int> nums2 = {-3,-1,2,4,5};
    Solution s;
    bool res = s.findSafeWalk(matrix, 3);
    cout << res << endl;
//    for (int word : res) {
//        cout << std::to_string(word) << ", ";
//    }
//    cout << endl;
    
    return 0;
}

