//  Tag: Binary Tree, Binary Search Tree
//  Time: O(H)
//  Space: O(1)
//  Ref: Leetcode-510
//  Note: -

//  There exists a binary search tree, and the binary tree node holds its parent node `parent`.
//  
//  In this question, you will get **any** node of the binary search tree.
//  You need to return the node after this node in the inorder traversal order, or *null* if there is no successor node.
//  
//  **Example 1**
//  
//  Input:
//  
//  ```plaintext
//  {2, 1, 3}
//  1
//  ```
//  
//  Output:
//  
//  ```plaintext
//  2
//  ```
//  
//  Explanation:
//  
//  A binary search tree looks like this:
//  
//  ```plaintext
//    2
//   / \
//  1   3
//  ```
//  
//  Obviously node 1's inorder successor node is 2.
//  
//  **Example 2**
//  
//  Input:
//  
//  ```plaintext
//  {2, 1, 3}
//  3
//  ```
//  
//  Output:
//  
//  ```plaintext
//  null
//  ```
//  
//  

/**
 * Definition of ParentTreeNode:
 * class ParentTreeNode {
 * public:
 *     int val;
 *     ParentTreeNode *parent, *left, *right;
 * }
 */

class Solution {
public:
    /**
     * @param node: random node in binary search tree
     * @return: the inorder successor of current node
     */
    ParentTreeNode* inorderSuccessor(ParentTreeNode *node) {
        // write your code here
        if (node->right) {
            ParentTreeNode *cur = node->right;
            while (cur->left) {
                cur = cur->left;
            }
            return cur;
        } else {
            ParentTreeNode *cur = node->parent;
            while (cur && cur->left != node) {
                node = cur;
                cur = cur->parent;
            }
            return cur;
        }
    }
};