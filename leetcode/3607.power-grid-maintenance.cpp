//  Tag: Array, Hash Table, Depth-First Search, Breadth-First Search, Union Find, Graph, Heap (Priority Queue), Ordered Set
//  Time: O(CLogC + QLogC)
//  Space: O(C)
//  Ref: -
//  Note: -

//  You are given an integer c representing c power stations, each with a unique identifier id from 1 to c (1‑based indexing).
//  These stations are interconnected via n bidirectional cables, represented by a 2D array connections, where each element connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly connected form a power grid.
//  Initially, all stations are online (operational).
//  You are also given a 2D array queries, where each query is one of the following two types:
//  
//  
//  [1, x]: A maintenance check is requested for station x. If station x is online, it resolves the check by itself. If station x is offline, the check is resolved by the operational station with the smallest id in the same power grid as x. If no operational station exists in that grid, return -1.
//  
//  
//  [2, x]: Station x goes offline (i.e., it becomes non-operational).
//  
//  
//  Return an array of integers representing the results of each query of type [1, x] in the order they appear.
//  Note: The power grid preserves its structure; an offline (non‑operational) node remains part of its grid and taking it offline does not alter connectivity.
//   
//  Example 1:
//  
//  Input: c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries = [[1,3],[2,1],[1,1],[2,2],[1,2]]
//  Output: [3,2,3]
//  Explanation:
//  
//  
//  Initially, all stations {1, 2, 3, 4, 5} are online and form a single power grid.
//  Query [1,3]: Station 3 is online, so the maintenance check is resolved by station 3.
//  Query [2,1]: Station 1 goes offline. The remaining online stations are {2, 3, 4, 5}.
//  Query [1,1]: Station 1 is offline, so the check is resolved by the operational station with the smallest id among {2, 3, 4, 5}, which is station 2.
//  Query [2,2]: Station 2 goes offline. The remaining online stations are {3, 4, 5}.
//  Query [1,2]: Station 2 is offline, so the check is resolved by the operational station with the smallest id among {3, 4, 5}, which is station 3.
//  
//  
//  Example 2:
//  
//  Input: c = 3, connections = [], queries = [[1,1],[2,1],[1,1]]
//  Output: [1,-1]
//  Explanation:
//  
//  There are no connections, so each station is its own isolated grid.
//  Query [1,1]: Station 1 is online in its isolated grid, so the maintenance check is resolved by station 1.
//  Query [2,1]: Station 1 goes offline.
//  Query [1,1]: Station 1 is offline and there are no other stations in its grid, so the result is -1.
//  
//  
//   
//  Constraints:
//  
//  1 <= c <= 105
//  0 <= n == connections.length <= min(105, c * (c - 1) / 2)
//  connections[i].length == 2
//  1 <= ui, vi <= c
//  ui != vi
//  1 <= queries.length <= 2 * 105
//  queries[i].length == 2
//  queries[i][0] is either 1 or 2.
//  1 <= queries[i][1] <= c
//  
//  

class UnionFind {
public:
    vector<int> arr;
    UnionFind(int n) {
        arr.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            arr[i] = i;
        }
    }

    void connect(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            arr[root_b] = root_a;
        }
    }

    int find(int a) {
        if (a == arr[a]) {
            return a;
        }

        arr[a] = find(arr[a]);
        return arr[a];
    }
    
};
class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int> res;
        UnionFind uf(c);
        vector<int> online(c + 1, true);
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> group;

        for (auto &x: connections) {
            uf.connect(x[0], x[1]);
        }

        for (int i = 1; i <= c; i++) {
            int root = uf.find(i);
            group[root].push(i);
        }

        for (auto &x: queries) {
            if (x[0] == 2) {
                online[x[1]] = false;
                continue;
            }

            if (online[x[1]]) {
                res.push_back(x[1]);
            } else {
                bool find = false;
                int root = uf.find(x[1]);
                while (!group[root].empty()) {
                    int top = group[root].top();
                    if (!online[top]) {
                        group[root].pop();
                    } else {
                        res.push_back(top);
                        find = true;
                        break;
                    }
                }
                if (!find) {
                    res.push_back(-1);
                }
            }
        }
    
        return res;
    }
};