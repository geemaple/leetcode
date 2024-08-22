//  Tag: Array, Graph, Heap (Priority Queue), Shortest Path
//  Time: O(VlogE)
//  Space: O(V+E)
//  Ref: -
//  Note: -

//  You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
//  Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
//  If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.
//   
//  Example 1:
//  
//  
//  Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
//  Output: 0.25000
//  Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.
//  
//  Example 2:
//  
//  
//  Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
//  Output: 0.30000
//  
//  Example 3:
//  
//  
//  Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
//  Output: 0.00000
//  Explanation: There is no path between 0 and 2.
//  
//   
//  Constraints:
//  
//  2 <= n <= 10^4
//  0 <= start, end < n
//  start != end
//  0 <= a, b < n
//  a != b
//  0 <= succProb.length == edges.length <= 2*10^4
//  0 <= succProb[i] <= 1
//  There is at most one edge between every two nodes.
//  
//  

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int, unordered_map<int, double>> graph;
        for (int i = 0; i < edges.size(); i++) {
            int x = edges[i][0];
            int y = edges[i][1];
            graph[x][y] = succProb[i];
            graph[y][x] = succProb[i];
        }

        priority_queue<pair<double, int>> q;
        unordered_set<int> visited;
        q.push({1, start_node});
        while (!q.empty()) {
            auto [prob, cur] = q.top();
            q.pop();

            if (visited.count(cur) > 0) {
                continue;
            }
            if (cur == end_node) {
                return prob;
            }

            visited.insert(cur);
            for (auto [node, node_prob]: graph[cur]) {
                if (visited.count(node) == 0) {
                    q.push({prob * node_prob, node});
                }
            }
        }

        return 0;
    }
};