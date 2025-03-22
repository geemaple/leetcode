//  Tag: Depth-First Search, Breadth-First Search, Union Find, Graph
//  Time: O(E + V)
//  Space: O(V)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/-ZFA0_oaUDo

//  You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
//  Return the number of complete connected components of the graph.
//  A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
//  A connected component is said to be complete if there exists an edge between every pair of its vertices.
//   
//  Example 1:
//  
//  
//  Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
//  Output: 3
//  Explanation: From the picture above, one can see that all of the components of this graph are complete.
//  
//  Example 2:
//  
//  
//  Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
//  Output: 1
//  Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
//  
//   
//  Constraints:
//  
//  1 <= n <= 50
//  0 <= edges.length <= n * (n - 1) / 2
//  edges[i].length == 2
//  0 <= ai, bi <= n - 1
//  ai != bi
//  There are no repeated edges.
//  
//  

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int res = 0;
        unordered_set<int> visited;
        for (int i = 0; i < n; i++) {
            if (dfs(graph, i, visited)) {
                res++;
            }
        }
        return res;
    }

    bool dfs(unordered_map<int, vector<int>>& graph, int node, unordered_set<int>& visited) {
        if (visited.count(node)) {
            return false;
        }

        stack<int> stk;
        stk.push(node);
        visited.insert(node);
        int vertex = 0;
        int edge = 0;

        while (!stk.empty()) {
            int cur = stk.top();
            stk.pop();
            vertex++;
            edge += graph[cur].size();

            for (int neighbor : graph[cur]) {
                if (!visited.count(neighbor)) {
                    visited.insert(neighbor);
                    stk.push(neighbor);
                }
            }
        }

        return vertex * (vertex - 1) == edge;
    }
};

class UnionFind {
public:
    vector<int> table;
    vector<int> edges;
    vector<int> count;

    UnionFind(int n) {
        table.resize(n);
        edges.resize(n);
        count.resize(n);
        for (int i = 0; i < n; i++) {
            table[i] = i;
            edges[i] = 0;
            count[i] = 1;
        }
    }

    void connect(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            table[root_a] = root_b;
            count[root_b] += count[root_a];
            edges[root_b] += edges[root_a];
        }
        edges[root_b] += 1;
    }

    int find(int a) {
        if (a == table[a]) {
            return a;
        }

        table[a] = find(table[a]);
        return table[a];
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto &e: edges) {
            uf.connect(e[0], e[1]);
        }

        unordered_set<int> visited;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int root = uf.find(i);
            if (visited.count(root) > 0) {
                continue;
            }
            visited.insert(root);
            int count = uf.count[root] * (uf.count[root] - 1) / 2;
            if (count == uf.edges[root]) {
                res += 1;
            }
        }

        return res;
    }
};