//  Tag: Array, Tree, Depth-First Search, Breadth-First Search, Graph
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/r2iiA5VBwRs

//  There is an undirected tree with n nodes labeled from 0 to n - 1, rooted at node 0. You are given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//  At every node i, there is a gate. You are also given an array of even integers amount, where amount[i] represents:
//  
//  the price needed to open the gate at node i, if amount[i] is negative, or,
//  the cash reward obtained on opening the gate at node i, otherwise.
//  
//  The game goes on as follows:
//  
//  Initially, Alice is at node 0 and Bob is at node bob.
//  At every second, Alice and Bob each move to an adjacent node. Alice moves towards some leaf node, while Bob moves towards node 0.
//  For every node along their path, Alice and Bob either spend money to open the gate at that node, or accept the reward. Note that:
//  	
//  If the gate is already open, no price will be required, nor will there be any cash reward.
//  If Alice and Bob reach the node simultaneously, they share the price/reward for opening the gate there. In other words, if the price to open the gate is c, then both Alice and Bob pay c / 2 each. Similarly, if the reward at the gate is c, both of them receive c / 2 each.
//  
//  
//  If Alice reaches a leaf node, she stops moving. Similarly, if Bob reaches node 0, he stops moving. Note that these events are independent of each other.
//  
//  Return the maximum net income Alice can have if she travels towards the optimal leaf node.
//   
//  Example 1:
//  
//  
//  Input: edges = [[0,1],[1,2],[1,3],[3,4]], bob = 3, amount = [-2,4,2,-4,6]
//  Output: 6
//  Explanation: 
//  The above diagram represents the given tree. The game goes as follows:
//  - Alice is initially on node 0, Bob on node 3. They open the gates of their respective nodes.
//    Alice's net income is now -2.
//  - Both Alice and Bob move to node 1. 
//    Since they reach here simultaneously, they open the gate together and share the reward.
//    Alice's net income becomes -2 + (4 / 2) = 0.
//  - Alice moves on to node 3. Since Bob already opened its gate, Alice's income remains unchanged.
//    Bob moves on to node 0, and stops moving.
//  - Alice moves on to node 4 and opens the gate there. Her net income becomes 0 + 6 = 6.
//  Now, neither Alice nor Bob can make any further moves, and the game ends.
//  It is not possible for Alice to get a higher net income.
//  
//  Example 2:
//  
//  
//  Input: edges = [[0,1]], bob = 1, amount = [-7280,2350]
//  Output: -7280
//  Explanation: 
//  Alice follows the path 0->1 whereas Bob follows the path 1->0.
//  Thus, Alice opens the gate at node 0 only. Hence, her net income is -7280. 
//  
//   
//  Constraints:
//  
//  2 <= n <= 105
//  edges.length == n - 1
//  edges[i].length == 2
//  0 <= ai, bi < n
//  ai != bi
//  edges represents a valid tree.
//  1 <= bob < n
//  amount.length == n
//  amount[i] is an even integer in the range [-104, 104].
//  
//  

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size() + 1;
        unordered_map<int, vector<int>> graph;
        for (auto e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        vector<int> bob_visited(n, false);
        bob_visited[bob] = true;
        vector<int> bob_path;
        bob_path.push_back(bob);
        bob_dfs(graph, bob_visited, bob, bob_path);
        vector<int> bob_dist(n, INT_MAX);
        for (int i = 0; i < bob_path.size(); i++) {
            bob_dist[bob_path[i]] = i;
        }

        vector<int> alice_visited(n, false);
        alice_visited[0] = true;
        return alice_dfs(graph, 0,  alice_visited, amount, 0, bob_dist);
    }

    int alice_dfs(unordered_map<int, vector<int>> &graph, int alice, vector<int> &visited, vector<int>& amount, int step, vector<int> &bob_dist) {
        int score = 0;
        if (step < bob_dist[alice]) {
            score += amount[alice];
        } else if (step == bob_dist[alice]) {
            score += amount[alice] / 2;
        }

        int total = INT_MIN;
        for (auto &x: graph[alice]) {
            if (!visited[x]) {
                visited[x] = true;
                total = max(total, alice_dfs(graph, x, visited, amount, step + 1, bob_dist));
                visited[x] = false;
            }
        }

        return total == INT_MIN ? score : score + total; 
    }

    bool bob_dfs(unordered_map<int, vector<int>> &graph, vector<int> &visited, int bob, vector<int> &path) {
        if (bob == 0) {
            return true;
        }

        for (auto &x : graph[bob]) {
            if (!visited[x]) {
                visited[x] = true;
                path.push_back(x);
                if (bob_dfs(graph, visited, x, path)) {
                    return true;
                }
                path.pop_back();
                visited[x] = false;
            }
        }

        return false;
    }

};