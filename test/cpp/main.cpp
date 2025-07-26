#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <stack>
#include <set>

using namespace std;

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
        int xor = nums[i];
        for (auto &j : graph[i]) {
            if (j != p) {
                xor ^= dfs(nums, graph, j, i);
            }
        }

        for (auto &j : graph[i]) {
            if (j == p) {
                dfs2(nums, graph, j, i, xor, x);
            }
        }

        return one;
    }

    int dfs2(vector<int>& nums, vector<vector<int>> &graph, int i, int p, int one, int anc) {
        int xor = nums[i];
        for (auto &j : graph[i]) {
            if (j != p) {
                xor ^= dfs(nums, graph, j, i, one, anc);
            }
        }

        if (p != anc) {
            int biggest = max({one, xor, total ^ one ^ xor});
            int smallest = min({one, xor, total ^ one ^ xor});
            res = min(res, biggest - smallest);
        }

        return one;
    }
};

int main() {
    std::string str = "aaba*";
    
    vector<int> nums = {1,5,5,4,11};
    
    vector<vector<int>> edges = {
        {0,1},{1,2},{1,3},{3,4}
    };
    
//    vector<vector<int>> edges = {
//        {0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}
//    };
    
    
//
//    
//    
//    vector<int> nums = {7,8,8,3,8,1,5,3,5,4};
//    vector<int> end = {3,4,5,6};
    vector<int> profit = {1,3,5,1};
    Solution s;
    int res = s.minimumScore(nums, edges);
    cout << res << endl;
    return 0;
}

