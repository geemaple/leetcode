//  Tag: Segment Tree
//  Time: O(logN)
//  Space: O(1)
//  Ref: -
//  Note: -

//  For a `Maximum Segment Tree`, which each node has an extra value `max` to store the maximum value in this node's interval.
//  
//  Implement a `modify` function with three parameter `root`, `index` and `value` to change the node's change the node's value with _**[start, end] = [index, index]**_ to the new given value in segment tree with root `root`.
//  Guarantee every node in segment tree still has the  **max**  attribute with the correct value after change.
//  
//  **Example 1:**
//  ```
//  Input："[1,4,max=3][1,2,max=2][3,4,max=3][1,1,max=2][2,2,max=1][3,3,max=0][4,4,max=3]",2,4
//  Output："[1,4,max=4][1,2,max=4][3,4,max=3][1,1,max=2][2,2,max=4][3,3,max=0][4,4,max=3]"
//  Explanation：
//  For segment tree:
//  
//  	                      [1, 4, max=3]
//  	                    /                \
//  	        [1, 2, max=2]                [3, 4, max=3]
//  	       /              \             /             \
//  	[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=3]
//  
//  if call modify(root, 2, 4), we can get:
//  
//  	                      [1, 4, max=4]
//  	                    /                \
//  	        [1, 2, max=4]                [3, 4, max=3]
//  	       /              \             /             \
//  	[1, 1, max=2], [2, 2, max=4], [3, 3, max=0], [4, 4, max=3]
//  ```
//  
//  
//  **Example 2:**
//  ```
//  Input："[1,4,max=3][1,2,max=2][3,4,max=3][1,1,max=2][2,2,max=1][3,3,max=0][4,4,max=3]",4,0
//  Output："[1,4,max=4][1,2,max=4][3,4,max=0][1,1,max=2][2,2,max=4][3,3,max=0][4,4,max=0]"
//  Explanation：
//  For segment tree:
//  
//  	                      [1, 4, max=3]
//  	                    /                \
//  	        [1, 2, max=2]                [3, 4, max=3]
//  	       /              \             /             \
//  	[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=3]
//  if call modify(root, 4, 0), we can get:
//  	
//  	                      [1, 4, max=2]
//  	                    /                \
//  	        [1, 2, max=2]                [3, 4, max=0]
//  	       /              \             /             \
//  	[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=0]
//  ```
//  
//  We suggest you finish problem [Segment Tree Build](http://www.lintcode.com/problem/segment-tree-build/ "Segment Tree Build") and [Segment Tree Query](http://www.lintcode.com/problem/segment-tree-query/ "Segment Tree Query") first.

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
     * @param root: The root of segment tree.
     * @param index: index.
     * @param value: value
     * @return: nothing
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        // write your code here
        if (index == root->start && index == root->end) {
            root->max = value;
            return;
        }

        int mid = (root->start + root->end) / 2;
        if (index <= mid) {
            modify(root->left, index, value);
        } else {
            modify(root->right, index, value);
        }
        root->max = max(root->left->max, root->right->max);
    }
};