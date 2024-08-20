//  Tag: Depth-First Search, Breadth-First Search, Union Find, Graph
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  In this problem, a tree is an undirected graph that is connected and has no cycles.
//  You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
//  Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.
//   
//  Example 1:
//  
//  
//  Input: edges = [[1,2],[1,3],[2,3]]
//  Output: [2,3]
//  
//  Example 2:
//  
//  
//  Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
//  Output: [1,4]
//  
//   
//  Constraints:
//  
//  n == edges.length
//  3 <= n <= 1000
//  edges[i].length == 2
//  1 <= ai < bi <= edges.length
//  ai != bi
//  There are no repeated edges.
//  The given graph is connected.
//  
//  

class UnionFind {
public:
    vector<int> nodes;
    UnionFind(int n): nodes(n + 1) {
        iota(nodes.begin(), nodes.end(), 0);
    } 
    
    int find(int a) {
        if (a == nodes[a]) {
            return a;
        }

        nodes[a] = find(nodes[a]);
        return nodes[a];
    }

    bool connect(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a == root_b) {
            return false;
        } else {
            nodes[root_a] = root_b;
            return true;
        }
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for (auto &x: edges) {
            if (!uf.connect(x[0], x[1])) {
                return x;
            }
        }

        return vector<int>{-1, -1};
    }
};