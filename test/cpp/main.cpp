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
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int directions[5] = {-1, 0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();

        vector<pair<int, int>> index_queries;
        for (int i = 0; i < queries.size(); i++) {
            index_queries.emplace_back(queries[i], i);
        }
        sort(index_queries.begin(), index_queries.end());
        priority_queue<tuple<int, int, int>> q;
        q.push({-grid[0][0], 0, 0});
        grid[0][0] = 0;

        vector<int> res(queries.size(), 0);
        int count = 0;
        for (auto &p: index_queries) {
            while (!q.empty() && -get<0>(q.top()) < p.first) {
                auto [val, x, y] = q.top();
                q.pop();
                count += 1;
                for (int d = 0; d < 4; d++) {
                    int dx = x + directions[d];
                    int dy = y + directions[d + 1];
                    if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy]) {
                        q.push({-grid[dx][dy], dx, dy});
                        grid[dx][dy] = 0;
                    }
                }
            }
            
            res[p.second] = count;
        }
        return res;
    }
};

int main() {
    std::string str = "aeioqq";
    
    vector<vector<int>> matrix = {
        {1,2,3},{2,5,7},{3,5,1}
    };
//    
//    
//    
//    vector<int> nums = {7,8,8,3,8,1,5,3,5,4};
//    vector<int> end = {3,4,5,6};
    vector<int> profit = {5,6,2};
    Solution s;
    vector<int> res = s.maxPoints(matrix, profit);

    return 0;
}

