//  Tag: Dynamic Programming, Depth-First Search, Breadth-First Search, Graph, Heap (Priority Queue), Shortest Path
//  Time: O(ElogV)
//  Space: O(E+V)
//  Ref: -
//  Note: -

//  There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
//  You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.
//   
//  Example 1:
//  
//  
//  Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
//  Output: 700
//  Explanation:
//  The graph is shown above.
//  The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
//  Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
//  
//  Example 2:
//  
//  
//  Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
//  Output: 200
//  Explanation:
//  The graph is shown above.
//  The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
//  
//  Example 3:
//  
//  
//  Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
//  Output: 500
//  Explanation:
//  The graph is shown above.
//  The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
//  
//   
//  Constraints:
//  
//  1 <= n <= 100
//  0 <= flights.length <= (n * (n - 1) / 2)
//  flights[i].length == 3
//  0 <= fromi, toi < n
//  fromi != toi
//  1 <= pricei <= 104
//  There will not be any multiple flights between two cities.
//  0 <= src, dst, k < n
//  src != dst
//  
//  

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> cost(n, INT_MAX);
        cost[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> tmp = cost;
            for (auto &x: flights) {
                if (cost[x[0]] < INT_MAX && cost[x[0]] + x[2] < tmp[x[1]]) {
                    tmp[x[1]] = cost[x[0]] + x[2];
                }
            }
            cost = tmp;
        }
        return cost[dst] < INT_MAX ? cost[dst]: -1;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<unordered_map<int, int>> graph(n);
        for (auto &x: flights) {
            graph[x[0]][x[1]] = x[2];
        }

        vector<int> distances(n, INT_MAX);
        vector<int> costs(n, INT_MAX);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;
        q.push({0, src, 0});
        distances[src] = 0;
        costs[src] = 0;
        while (!q.empty()) {
            auto [cost, cur, stop] = q.top();
            q.pop();

            if (cur == dst) {
                return cost;
            }

            if (stop == k + 1) {
                continue;
            }

            for (auto &[node, node_cost]: graph[cur]) {
                if (costs[node] == INT_MAX || costs[node] > cost + node_cost || distances[node] > stop + 1) {
                    costs[node] = cost + node_cost;
                    distances[node] = stop + 1;
                    q.push({cost + node_cost, node, stop + 1});
                }
            }
        }
        return -1;
    }
};