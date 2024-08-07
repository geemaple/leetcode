//  Tag: Segment Tree
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  The structure of Segment Tree is a binary tree which each node has two attributes `start` and `end` denote an segment / interval.
//  
//  `start` and `end` are both integers, they should be assigned in following rules:
//  
//  - The root's `start` and `end` is given by `build` method.
//  - The left child of node A has `start=A.left, end=(A.left + A.right) / 2`.
//  - The right child of node A has `start=(A.left + A.right) / 2 + 1, end=A.right`.
//  - if `start` equals to `end`, there will be no children for this node.
//  
//  Implement a `build` method with a given array, so that we can create a corresponding segment tree with every node value represent the corresponding interval max value in the array, return the root of this segment tree.
//  
//  ```
//  Input: [3,2,1,4]
//  Explanation:
//  The segment tree will be
//            [0,3](max=4)
//            /          \
//         [0,1]         [2,3]    
//        (max=3)       (max=4)
//        /   \          /    \    
//     [0,0]  [1,1]    [2,2]  [3,3]
//    (max=3)(max=2)  (max=1)(max=4)
//  ```
//  
//  Segment Tree (a.k.a Interval Tree) is an advanced data structure which can support queries like:
//  
//  - which of these intervals contain a given point
//  - which of these points are in a given interval
//  
//  See wiki:
//  [Segment Tree](https://en.wikipedia.org/wiki/Segment_tree "Segment Tree")
//  [Interval Tree](https://en.wikipedia.org/wiki/Interval_tree "Interval Tree")

/**
 * Definition of SegmentTreeNode:
 * class SegmentTreeNode {
 * public:
 *     int start, end, max;
 *     SegmentTreeNode *left, *right;
 *     SegmentTreeNode(int start, int end, int max) {
 *         this->start = start;
 *         this->end = end;
 *         this->max = max;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param a: a list of integer
     * @return: The root of Segment Tree
     */
    SegmentTreeNode* build(vector<int> &a) {
        // write your code here
        return helper(a, 0, a.size() - 1);
    }

    SegmentTreeNode* helper(vector<int> &a, int start, int end) {
        if (start > end) {
            return nullptr;
        }

        SegmentTreeNode *node = new SegmentTreeNode(start, end, a[start]);
        if (start == end) {
            return node;
        }
        int mid = (start + end) / 2;
        node->left = helper(a, start, mid);
        node->right = helper(a, mid + 1, end);
        node->max = max(node->left->max, node->right->max);
        return node;
    }
};