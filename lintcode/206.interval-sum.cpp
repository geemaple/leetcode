//  Tag: Segment Tree
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list.
//  Each query has two integers `[start, end]`.
//  For each query, calculate the sum of numbers between index start and end in the given array and return in the result list.
//  
//  **Example 1:**
//  ```
//  Input: array = [1,2,7,8,5],  queries = [(0,4),(1,2),(2,4)]
//  Output: [23,9,20]
//  ```
//  
//  **Example 2:**
//  ```
//  Input: array = [4,3,1,2],  queries = [(1,2),(0,2)]
//  Output: [4,8]
//  ```
//  
//  We suggest you finish problem [Segment Tree Build](https://www.lintcode.com/problem/segment-tree-build/ ), [Segment Tree Query](https://www.lintcode.com/problem/segment-tree-query/) and [Segment Tree Modify](https://www.lintcode.com/problem/segment-tree-modify/) first.

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param a: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &a, vector<Interval> &queries) {
        // write your code here
        vector<long long> prefix = {0};
        for (int x: a) {
            prefix.push_back(prefix.back() + x);
        }

        vector<long long> res;
        for (auto &interval: queries) {
            res.push_back(prefix[interval.end + 1] - prefix[interval.start]);
        }

        return res;
    }
};

class SegmentTree {
public:
    vector<long long> seg;
    SegmentTree(vector<int> &a) {
        int n = a.size();
        seg.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    void build(vector<int> &a, int v, int i, int j) {
        if (i == j) {
            seg[v] = a[i];
            return;
        }
        int m = (i + j) / 2;
        build(a, 2 * v, i, m);
        build(a, 2 * v + 1, m + 1, j);
        seg[v] = seg[2 * v] + seg[2 * v + 1];
    }

    long long query(int v, int i, int j, int l, int r) {
        if (l > r) {
            return 0;
        }
        
        if (l == i && r == j) {
            return seg[v];
        }

        int m = (i + j) / 2;
        long long left = query(2 * v, i, m, l, min(m, r));
        long long right = query(2 * v + 1, m + 1, j, max(m + 1, l), r);
        return left + right;
    }
};

class Solution {
public:
    /**
     * @param a: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &a, vector<Interval> &queries) {
        // write your code here
        int n = a.size();
        SegmentTree seg = SegmentTree(a);
        vector<long long> res;
        for (auto &x: queries) {
            res.push_back(seg.query(1, 0, n - 1, x.start, x.end));
        }
        return res;
    }
};

class SegTreeNode {
public:
    int start, end;
    long long sum;
    SegTreeNode *left, *right;
    SegTreeNode(int start, int end) {
        this->start = start;
        this->end = end;
        this->sum = 0;
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
    /**
     * @param a: An integer list
     * @param queries: An query list
     * @return: The result list
     */
    vector<long long> intervalSum(vector<int> &a, vector<Interval> &queries) {
        // write your code here
        SegTreeNode *root = build(0, a.size() - 1, a);
        vector<long long> res;
        for (auto &interval: queries) {
            res.push_back(query(root, interval.start, interval.end));
        }
        return res;
    }

    long long query(SegTreeNode *root, int start, int end) {
        if (!root) {
            return 0;
        }

        if (start == root->start && end == root->end) {
            return root->sum;
        }

        int mid = root->start + (root->end - root->start) / 2;
        if (end <= mid) {
            return query(root->left, start, end);
        } else if (start > mid) {
            return query(root->right, start, end);
        } else {
            return query(root->left, start, mid) + query(root->right, mid + 1, end);
        }
    }

    SegTreeNode *build(int start, int end, vector<int> &vals) {
        if (start > end) {
            return nullptr;
        }

        SegTreeNode *node = new SegTreeNode(start, end);
        if (start == end) {
            node->sum = vals[start];
            return node;
        }
        int mid = start + (end - start) / 2;
        node->left = build(start, mid, vals);
        node->right = build(mid + 1, end, vals);
        node->sum = node->left->sum + node->right->sum;
        return node;
    }
};