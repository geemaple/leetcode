//  Tag: Graph Theory, Heap (Priority Queue), Shortest Path
//  Time: O(MLogN)
//  Space: O(N + M)
//  Ref: -
//  Note: -

//  You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.
//  Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.
//  The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.
//  Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.
//   
//  Example 1:
//  
//  Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]
//  Output: 5
//  Explanation: 
//  
//  
//  Use the path 0 → 1 (cost 3).
//  At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
//  Total cost is 3 + 2 = 5.
//  
//  
//  Example 2:
//  
//  Input: n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]
//  Output: 3
//  Explanation:
//  
//  No reversal is needed. Take the path 0 → 2 (cost 1), then 2 → 1 (cost 1), then 1 → 3 (cost 1).
//  Total cost is 1 + 1 + 1 = 3.
//  
//  
//   
//  Constraints:
//  
//  2 <= n <= 5 * 104
//  1 <= edges.length <= 105
//  edges[i] = [ui, vi, wi]
//  0 <= ui, vi <= n - 1
//  1 <= wi <= 1000
//  
//  

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, w * 2});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [cost, cur] = pq.top();
            pq.pop();

            if (visited[cur]) {
                continue;
            }
            visited[cur] = true;
            if (cur == n - 1) {
                return cost;
            }

            for (auto& [next, weight] : graph[cur]) {
                pq.push({cost + weight, next});
            }
        }

        return -1;
    }
};