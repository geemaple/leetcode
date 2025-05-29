//  Tag: Tree, Depth-First Search, Breadth-First Search
//  Time: O(N ^ 2 + M ^ 2)
//  Space: O(N + M)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/e5Am36Vfl-M

//  There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.
//  You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.
//  Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.
//  Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.
//  Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
//   
//  Example 1:
//  
//  Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2
//  Output: [9,7,9,8,8]
//  Explanation:
//  
//  For i = 0, connect node 0 from the first tree to node 0 from the second tree.
//  For i = 1, connect node 1 from the first tree to node 0 from the second tree.
//  For i = 2, connect node 2 from the first tree to node 4 from the second tree.
//  For i = 3, connect node 3 from the first tree to node 4 from the second tree.
//  For i = 4, connect node 4 from the first tree to node 4 from the second tree.
//  
//  
//  Example 2:
//  
//  Input: edges1 = [[0,1],[0,2],[0,3],[0,4]], edges2 = [[0,1],[1,2],[2,3]], k = 1
//  Output: [6,3,3,3,3]
//  Explanation:
//  For every i, connect node i of the first tree with any node of the second tree.
//  
//   
//  Constraints:
//  
//  2 <= n, m <= 1000
//  edges1.length == n - 1
//  edges2.length == m - 1
//  edges1[i].length == edges2[i].length == 2
//  edges1[i] = [ai, bi]
//  0 <= ai, bi < n
//  edges2[i] = [ui, vi]
//  0 <= ui, vi < m
//  The input is generated such that edges1 and edges2 represent valid trees.
//  0 <= k <= 1000
//  
//  

class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        unordered_map<int, vector<int>> graph1;
        unordered_map<int, vector<int>> graph2;

        for (auto &e: edges1) {
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }

        for (auto &e: edges2) {
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        int dist = 0;
        for (int i = 0; i < graph2.size(); i++) {
            dist = max(dist, count(i, graph2, k - 1));
        }
        vector<int> res;
        for (int i = 0; i < graph1.size(); i++) {
            res.push_back(count(i, graph1, k) + dist);
        }

        return res;
    }

    int count(int node, unordered_map<int, vector<int>> &graph, int k) {
        if (k == 0) {
            return 1;
        }

        int res = 0;
        queue<int> q;
        q.push(node);
        vector<bool> visited(graph.size(), false);
        visited[node] = true;

        while (k >= 0 && !q.empty()) {
            int size = q.size();
            k -= 1;
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                res += 1;
                for (auto &neighbor: graph[cur]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
        }
        return res;
    }

};