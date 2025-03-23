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
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> graph;
        int mod = 1e9 + 7;
        for (auto &r: roads) {
            graph[r[0]].emplace_back(r[1], r[2]);
            graph[r[1]].emplace_back(r[0], r[2]);
        }

        vector<int> time(n, 0);
        vector<int> count(n, 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.emplace(0, 0);

        while (!q.empty()) {
            auto [cost, cur] = q.top();
            q.pop();

            for (auto &[neighbor, t]: graph[cur]) {
                cout << neighbor << endl;
                if (time[neighbor] == 0 || time[neighbor] > time[cur] + t) {
                    time[neighbor] = time[cost] + t;
                    count[neighbor] = count[cost];
                    q.emplace(time[neighbor], neighbor);
                } else if (time[neighbor] == time[cur] + t) {
                    count[neighbor] = (count[neighbor] + count[cur]) % mod;
                }
            }
        }
        return count[n - 1];
    }
};

int main() {
    std::string str = "aeioqq";
    
    vector<vector<int>> matrix = {
        {0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}
    };
//    
//    
//    
//    vector<int> nums = {7,8,8,3,8,1,5,3,5,4};
//    vector<int> end = {3,4,5,6};
    vector<int> profit = {1,2,6,4};
    Solution s;
    int res = s.countPaths(7, matrix);

    return 0;
}

