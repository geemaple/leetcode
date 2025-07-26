//  Tag: Array, Bit Manipulation, Tree, Depth-First Search
//  Time: O(N^2)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/c-HYjUyuDM8

//  There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
//  You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
//  Remove two distinct edges of the tree to form three connected components. For a pair of removed edges, the following steps are defined:
//  
//  Get the XOR of all the values of the nodes for each of the three components respectively.
//  The difference between the largest XOR value and the smallest XOR value is the score of the pair.
//  
//  
//  For example, say the three components have the node values: [4,5,7], [1,9], and [3,3,3]. The three XOR values are 4 ^ 5 ^ 7 = 6, 1 ^ 9 = 8, and 3 ^ 3 ^ 3 = 3. The largest XOR value is 8 and the smallest XOR value is 3. The score is then 8 - 3 = 5.
//  
//  Return the minimum score of any possible pair of edge removals on the given tree.
//   
//  Example 1:
//  
//  
//  Input: nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
//  Output: 9
//  Explanation: The diagram above shows a way to make a pair of removals.
//  - The 1st component has nodes [1,3,4] with values [5,4,11]. Its XOR value is 5 ^ 4 ^ 11 = 10.
//  - The 2nd component has node [0] with value [1]. Its XOR value is 1 = 1.
//  - The 3rd component has node [2] with value [5]. Its XOR value is 5 = 5.
//  The score is the difference between the largest and smallest XOR value which is 10 - 1 = 9.
//  It can be shown that no other pair of removals will obtain a smaller score than 9.
//  
//  Example 2:
//  
//  
//  Input: nums = [5,5,2,4,4,2], edges = [[0,1],[1,2],[5,2],[4,3],[1,3]]
//  Output: 0
//  Explanation: The diagram above shows a way to make a pair of removals.
//  - The 1st component has nodes [3,4] with values [4,4]. Its XOR value is 4 ^ 4 = 0.
//  - The 2nd component has nodes [1,0] with values [5,5]. Its XOR value is 5 ^ 5 = 0.
//  - The 3rd component has nodes [2,5] with values [2,2]. Its XOR value is 2 ^ 2 = 0.
//  The score is the difference between the largest and smallest XOR value which is 0 - 0 = 0.
//  We cannot obtain a smaller score than 0.
//  
//   
//  Constraints:
//  
//  n == nums.length
//  3 <= n <= 1000
//  1 <= nums[i] <= 108
//  edges.length == n - 1
//  edges[i].length == 2
//  0 <= ai, bi < n
//  ai != bi
//  edges represents a valid tree.
//  
//  

class Solution {
public:
    int res = INT_MAX;
    int total = 0;
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        for (auto &e :  edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            total ^= nums[i];
        }

        dfs(nums, graph, 0, -1);
        
        return res;
    }

    int dfs(vector<int>& nums, vector<vector<int>> &graph, int i, int p) {
        int one = nums[i];
        for (auto &j : graph[i]) {
            if (j != p) {
                one ^= dfs(nums, graph, j, i);
            }
        }

        for (auto &j : graph[i]) {
            if (j == p) {
                dfs2(nums, graph, j, i, one, i);
            }
        }

        return one;
    }

    int dfs2(vector<int>& nums, vector<vector<int>> &graph, int i, int p, int one, int anc) {
        int sec = nums[i];
        for (auto &j : graph[i]) {
            if (j != p) {
                sec ^= dfs2(nums, graph, j, i, one, anc);
            }
        }

        if (p != anc) {
            int biggest = max({one, sec, total ^ one ^ sec});
            int smallest = min({one, sec, total ^ one ^ sec});
            res = min(res, biggest - smallest);
        }

        return sec;
    }
};

class Solution {
public:
    int dp[1000] = {}, last[1000] = {};
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        int ids = 0;
        int res = INT_MAX;
        vector<vector<int>> graph(n);
        for (auto &e :  edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        int all = dfs(nums, graph, 0, -1, ids);    

        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j < n; ++j) {
                int p1 = j < last[i] ? all ^ dp[i] : all ^ dp[i] ^ dp[j];
                int p2 = j < last[i] ? dp[i] ^ dp[j] : dp[i];
                res = min(res, max({p1, p2, dp[j]}) - min({p1, p2, dp[j]}));
            }
        return res;
    }

    int dfs(vector<int>& nums, vector<vector<int>> &graph, int i, int p, int &ids) {
        int id = ids++;
        int res = nums[i];
        for (auto j : graph[i])
            if (j != p)
                res ^= dfs(nums, graph, j, i, ids);
        last[id] = ids;
        return dp[id] = res;    
    }
};