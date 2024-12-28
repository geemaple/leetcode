//  Tag: Binary Tree, Binary Search Tree
//  Time: O(H)
//  Space: O(1)
//  Ref: Leetcode-285
//  Note: Successor

//  Given a binary search tree ([See Definition](http://www.lintcode.com/problem/validate-binary-search-tree/ "BST")) and a node in it, find the in-order successor of that node in the BST.
//  
//  If the given node has no in-order successor in the tree, return `null`.
//  
//  **Example 1:**
//  
//  ```
//  Input: {1,#,2}, node with value 1
//  Output: 2
//  Explanation:
//    1
//     \
//      2
//  ```
//  
//  **Example 2:**
//  
//  ```
//  Input: {2,1,3}, node with value 1
//  Output: 2
//  Explanation: 
//      2
//     / \
//    1   3
//  ```
//  
//  [Binary Tree Representation](https://www.lintcode.com/help/binary-tree-representation/)
//  
//  It's guaranteed *p* is one node in the given tree. (You can directly compare the memory address to find p)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
        TreeNode *node = root;
        TreeNode *next = nullptr;
        while (node) {
            if (p->val < node->val) {
                next = node;
                node = node->left;
            } else {
                node = node->right;               
            }
        }

        return next;
    }
};

class Solution {
public:
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        // write your code here
        stack<TreeNode *>st;
        TreeNode *cur = root;
        bool find = false;
        while (!st.empty() || cur) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();

            if (find) {
                return cur;
            }

            if (cur == p) {
                find = true;
            }
            cur = cur->right;

        }

        return nullptr;
    }
};