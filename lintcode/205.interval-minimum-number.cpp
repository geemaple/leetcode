//  Tag: Segment Tree
//  Time: O(NlogN)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list.
//  Each query has two integers `[start, end]`.
//  For each query, calculate the minimum number between index start and end in the given array,and return  in the result list.
//  
//  **Example 1:**
//  ```
//  Input : array: [1,2,7,8,5], queries :[(1,2),(0,4),(2,4)] .Output: [2,1,5]
//  ```
//  **Example 2:**
//  ```
//  Input : array: [4,5,7,1], queries :[(1,2),(1,3)]. Output: [5,1]
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

class SegmentTreeNode {
    // platform has a hidden SegmentTreeNode, you can change SegmentTreeNode to MySegmentTreeNode to avoid confliction
public:
    int start, end, min;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int min): start(start), end(end), min(min), left(nullptr), right(nullptr) {}   
};

class SegmentTree {
public:
    SegmentTreeNode *root;
    SegmentTree(vector<int> &a) {
        root = build(a, 0, a.size() - 1);
    }

    SegmentTreeNode *build(vector<int> &a, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        SegmentTreeNode *node = new SegmentTreeNode(start, end, a[start]);
        if (start == end) {
            return node;
        }
        int mid = (start + end) / 2;
        node->left = build(a, start, mid);
        node->right = build(a, mid + 1, end);
        node->min = min(node->left->min, node->right->min);
        return node;
    }

    int query(SegmentTreeNode *node, int start, int end) {
        if (!node) {
            return -1;
        }

        if (start == node->start && end == node->end) {
            return node->min;
        }

        int mid = (node->start + node->end) / 2;
        if (end <= mid) {
            return query(node->left, start, end);
        } else if (start > mid) {
            return query(node->right, start, end);
        } else {
            int left_val = query(node->left, start, mid);
            int right_val = query(node->right, mid + 1, end);
            return min(left_val, right_val);
        }
    }
};

class Solution {
public:
    /**
     * @param a: An integer array
     * @param queries: An query list
     * @return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &a, vector<Interval> &queries) {
        // write your code here
        SegmentTree t(a);
        vector<int> res;
        for (auto &q: queries) {
            int val = t.query(t.root, q.start, q.end);
            res.push_back(val);
        }

        return res;
    }
};