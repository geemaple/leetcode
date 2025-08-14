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

class SegmentTree {
public:
    vector<int> seg;
    SegmentTree(vector<int> &baskets) {
        int n = baskets.size();
        int size = 4 * n;
        seg.resize(size);
        build(baskets, 1, 0, n - 1);
    }

    void update(int i) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }

    void build(vector<int> &baskets, int v, int i, int j) {
        if (i == j) {
            seg[v] = baskets[i];
            return;
        }

        int m = (i + j) / 2;
        build(baskets, 2 * v, i, m);
        build(baskets, 2 * v + 1, m + 1, j);
        update(v);
    }

    int query_and_update(int v, int i, int j, int val) {
        if (seg[v] < val) {
            return -1;
        }

        if (i == j) {
            seg[v] = -1;
            return i;
        }

        int m = (i + j) / 2;
        int t = query_and_update(2 * v, i, m, val);
        if (t == -1) {
            t = query_and_update(2 * v + 1, m + 1, j, val);
        }
        update(v);
        return t;
    }

};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        SegmentTree tree = SegmentTree(baskets);
        int res = 0;
        for (auto &x: fruits) {
            if (tree.query_and_update(1, 0, n - 1, x) == -1) {
                res += 1;
            }
        }
        return res;
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

