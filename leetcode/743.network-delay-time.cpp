//  Tag: Depth-First Search, Breadth-First Search, Graph, Heap (Priority Queue), Shortest Path
//  Time: O(ElogE)
//  Space: O(E+V)
//  Ref: -
//  Note: -

//  You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
//  We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
//   
//  Example 1:
//  
//  
//  Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
//  Output: 2
//  
//  Example 2:
//  
//  Input: times = [[1,2,1]], n = 2, k = 1
//  Output: 1
//  
//  Example 3:
//  
//  Input: times = [[1,2,1]], n = 2, k = 2
//  Output: -1
//  
//   
//  Constraints:
//  
//  1 <= k <= n <= 100
//  1 <= times.length <= 6000
//  times[i].length == 3
//  1 <= ui, vi <= n
//  ui != vi
//  0 <= wi <= 100
//  All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
//  
//  

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, unordered_map<int, int>> graph;
        for (auto &x: times) {
            graph[x[0]][x[1]] = x[2];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, k});
        unordered_set<int> visited;
        int res = 0;
        while (!q.empty()) {
            auto [delay, cur] = q.top();
            q.pop();
            if (visited.count(cur) > 0){
                continue;
            }
            visited.insert(cur);
            res = delay;

            for (auto &[node, time] : graph[cur]) {
                if (visited.count(node) == 0) {
                    q.push({time + delay, node});
                }
            }
        }

        return visited.size() == n ? res: -1;
    }
};