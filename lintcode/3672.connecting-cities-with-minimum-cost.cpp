//  Tag: Graph, Greedy, Union Find
//  Time: O(ElogE)
//  Space: O(E+V)
//  Ref: Leetcode-1135
//  Note: -

//  There are `n` cities in this question, and their numbers range from 1 to n.
//  
//  At the same time, there is a `connections` array and $connections[i] = [a_i, b_i, c_i]$, which means that the cost of connecting cities $a_i$ and $b_i$ is $c_i$.
//  
//  Please return the minimum cost required to connect all cities.
//  If all cities cannot be connected, return **-1**.
//  
//  **Example 1**
//  
//  Input:
//  
//  ```plaintext
//  3
//  [[1,2,1], [2,3,2], [1,3,3]]
//  ```
//  
//  Ouput:
//  
//  ```plaintext
//  3
//  ```
//  
//  Explanation:
//  
//  Choose `[1,2,1]` and `[2,3,2]` to connect all n cities. At this time, the cost is the least, which is 3.
//  
//  **Example 2**
//  
//  Input:
//  
//  ```plaintext
//  3
//  [[1,2,1]]
//  ```
//  
//  Output:
//  
//  ```plaintext
//  -1
//  ```
//  
//  Explanation:
//  
//  Unable to connect all cities according to `connections`.
//  
//  

class Solution {
public:
    /**
     * @param n: the number of cities
     * @param connections: the connection info between cities
     * @return: nothing
     */
    int minimumCost(int n, vector<vector<int>> &connections) {
        // write your code here
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto x: connections) {
            graph[x[0]].push_back(make_pair(x[1], x[2]));
            graph[x[1]].push_back(make_pair(x[0], x[2]));
        }

        unordered_set<int> visited;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push(make_pair(0, connections[0][0]));
        int res = 0;
        
        while (!q.empty()) {
            pair<int, int> top = q.top();
            q.pop();
            int city = top.second;
            int cost = top.first;
            if (visited.count(city) > 0) {
                continue;
            }
            visited.insert(city);
            res += cost;

            for (auto x: graph[city]) {
                if (visited.count(x.first) == 0) {
                    q.push(make_pair(x.second, x.first));
                }
            }
        }

        return visited.size() == n ? res : -1;

    }
};

class UnionFind {
public:
    vector<int> nodes;
    vector<int> sizes;
    UnionFind(int n): nodes(n + 1), sizes(n + 1 , 1) {
        for (int i = 0; i <= n; i++) {
            nodes[i] = i;
        }
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
            sizes[root_b] += sizes[root_a];
            return true;
        }
    }

    int sizeOf(int a) {
        int root_a = find(a);
        return sizes[root_a];
    }
};

class Solution {
public:
    /**
     * @param n: the number of cities
     * @param connections: the connection info between cities
     * @return: nothing
     */
    int minimumCost(int n, vector<vector<int>> &connections) {
        // write your code here
        sort(connections.begin(), connections.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });

        UnionFind uf(n);
        int res = 0;
        for (auto &x: connections) {
            if (uf.connect(x[0], x[1])) {
                res += x[2];
            }
        }

        return uf.sizeOf(1) == n ? res: -1;
    }
};