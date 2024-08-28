#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<unordered_map<int, int>> graph(n);
        for (auto &x: flights) {
            graph[x[0]][x[1]] = x[2];
        }

        vector<int> distances(n, INT_MAX);
        vector<int> costs(n, INT_MAX);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({0, src, 0});
        while (!q.empty()) {
            auto &[cost, cur, stop] = q.top();
            q.pop();

            if (cur == dst) {
                return cost;
            }

            if (stop == k + 1) {
                continue;
            }

            for (auto &[node, node_cost]: graph[cur]) {
                if (costs[node] == INT_MAX || costs[node] > cost + node_cost || distances[node] > stop + 1) {
                    costs[node] = cost + node_cost;
                    distances[node] = stop + 1;
                    q.push({costs[node], node, distances[node]});
                }
            }
        }
        return -1;

    }
};
//int main() {
//    vector<vector<int>> f = {{0,1,100}, {1,2,100}, {2,0,100}, {1,3,600}, {2,3,200}};
//    Solution s;
//    cout << "Longest Palindromic Substring: " << s.findCheapestPrice(4, f, 0, 3, 1) << endl;
//    return 0;
//}

int main() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
    q.push({100, 1, 0}); // (cost, node, stop)
    q.push({50, 2, 1});
    
    // Copying values
    auto [cost1, cur1, stop1] = q.top();
    cout << "Copy: " << cost1 << ", " << cur1 << ", " << stop1 << endl; // Outputs: 50, 2, 1
    
    // Referencing values
    auto &[cost2, cur2, stop2] = q.top();
    cout << "Reference: " << cost2 << ", " << cur2 << ", " << stop2 << endl; // Outputs: 50, 2, 1
    
    // Modifying via reference
//    cost2 += 10;  Modifies the original tuple in the queue
//    cout << "After modification: " << get<0>(q.top()) << endl; // Outputs: 60 (the original tuple is affected)

    return 0;
}
