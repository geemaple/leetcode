//  Tag: Binary Tree, Depth First Search/DFS, Divide and Conquer
//  Time: O(N)
//  Space: O(H)
//  Ref: Leetcode-156
//  Note: -

//  Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes.
//  Return the new root.
//  
//  **Example1**
//  
//  ```plain
//  Input: {1,2,3,4,5}
//  Output: {4,5,2,#,#,3,1}
//  Explanation:
//  The input is
//      1
//     / \
//    2   3
//   / \
//  4   5
//  and the output is
//     4
//    / \
//   5   2
//      / \
//     3   1
//  ```
//  
//  **Example2**
//  
//  ```plain
//  Input: {1,2,3,4}
//  Output: {4,#,2,3,1}
//  Explanation:
//  The input is
//      1
//     / \
//    2   3
//   /
//  4
//  and the output is
//     4
//      \
//       2
//      / \
//     3   1
//  ```
//  
//  

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode* upsideDownBinaryTree(TreeNode *root) {
        // write your code here
        if (!root || !root->left) {
            return root;
        }
        TreeNode *new_root = upsideDownBinaryTree(root->left);
        root->left->left = root->right;
        root->left->right = root;
        root->left = nullptr;
        root->right = nullptr;
        return new_root;
    }
};

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode* upsideDownBinaryTree(TreeNode *root) {
        // write your code here
        stack<TreeNode *> st;
        TreeNode * cur = root;
        while (cur) {
            st.push(cur);
            cur = cur->left;
        }

        TreeNode *dummy = new TreeNode(0); 
        TreeNode *pre = dummy;
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            pre->right = cur;
            pre->left = cur->right;
            pre = cur;
            cur->left = nullptr;
            cur->right = nullptr;
        }

        // fix dummy memory leak in real code
        return dummy->right;
    }
};

class Solution {
public:
    /**
     * @param root: the root of binary tree
     * @return: new root
     */
    TreeNode* upsideDownBinaryTree(TreeNode *root) {
        TreeNode * pre = nullptr;
        TreeNode *cur = root;
        TreeNode *rchild = nullptr;

        // like reverse single linked list with special right child
        while(cur){
            TreeNode *tmp = cur->left;
            
            cur->left = rchild;
            rchild = cur->right;
            
            cur->right = pre;
            
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};