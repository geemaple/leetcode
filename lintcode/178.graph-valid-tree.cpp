//  Tag: Union Find, Breadth First Search/BFS
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: LeetCode-261

//  Given `n` nodes labeled from `0` to `n - 1` and a list of `undirected` edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
//  
//  **Example 1:**
//  ```
//  Input: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
//  Output: true.
//  ```
//  
//  **Example 2:**
//  ```
//  Input: n = 5 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
//  Output: false.
//  ```
//  
//  You can assume that no duplicate edges will appear in edges. Since all edges are `undirected`, `[0, 1]` is the same as `[1, 0]` and thus will not appear together in edges.

class UionFind {
public:
    vector<int> table;
    UionFind(int n): table(n) {
        for (int i = 0; i < n; i++) {
            table[i] = i;
        }
    }

    int find(int a) {
        if (a == table[a]){
            return a;
        }

        table[a] = find(table[a]);
        return table[a];
    }

    bool connect(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            table[root_a] = root_b;
            return true;
        }

        return false;
    }
};
class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if (edges.size() != n - 1) {
            return false;
        }

        int count = n;
        UionFind uf = UionFind(n);
        for (auto &edge: edges) {
            int x = edge[0];
            int y = edge[1];
            if (uf.connect(x, y)) {
                count--;
            }
        }
        return count == 1;
    }
};

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool validTree(int n, vector<vector<int>> &edges) {
        // write your code here
        if (edges.size() != n - 1) {
            return false;
        }

        unordered_map<int, vector<int>> graph;
        for (auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> visited;
        queue<int> q;
        
        visited.insert(0);
        q.push(0);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto next_node: graph[cur]) {
                if (visited.count(next_node) == 0) {
                    visited.insert(next_node);
                    q.push(next_node);
                }

            }
        }

        return visited.size() == n;
    }
};