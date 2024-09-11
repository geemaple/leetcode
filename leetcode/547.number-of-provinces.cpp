//  Tag: Depth-First Search, Breadth-First Search, Union Find, Graph
//  Time: O(N^2)
//  Space: O(N)
//  Ref: -
//  Note: -

//  There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
//  A province is a group of directly or indirectly connected cities and no other cities outside of the group.
//  You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
//  Return the total number of provinces.
//   
//  Example 1:
//  
//  
//  Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
//  Output: 2
//  
//  Example 2:
//  
//  
//  Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
//  Output: 3
//  
//   
//  Constraints:
//  
//  1 <= n <= 200
//  n == isConnected.length
//  n == isConnected[i].length
//  isConnected[i][j] is 1 or 0.
//  isConnected[i][i] == 1
//  isConnected[i][j] == isConnected[j][i]
//  
//  

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(isConnected, i, visited);
                ++count;
            }
        }
        return count;
    }
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& visited) {
        visited[i] = true;
        for (int k = 0; k < isConnected.size(); ++k) {
            if (isConnected[i][k] == 1 && !visited[k]) {
                dfs(isConnected, k, visited);
            }
        }
    }
};

class UnionFind {
public:
    vector<int> table;
    UnionFind(int n) {
        table.resize(n);
        for (int i = 0; i < n; i++) {
            table[i] = i;
        }
    }

    int find(int a) {
        if (a == table[a]) {
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = n;
        UnionFind uf = UnionFind(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j ++) {
                if (isConnected[i][j] && uf.connect(i, j)) {
                    count--;
                }
            }
        }

        return count;
    }
};