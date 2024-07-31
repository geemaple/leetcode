//  Tag: Tree, Depth-First Search, Binary Search Tree, Binary Tree
//  Time: O(N)
//  Space: O(Height)
//  Ref: -
//  Note: BST

//  Given the root of a binary tree, determine if it is a valid binary search tree (BST).
//  A valid BST is defined as follows:
//  
//  The left subtree of a node contains only nodes with keys less than the node's key.
//  The right subtree of a node contains only nodes with keys greater than the node's key.
//  Both the left and right subtrees must also be binary search trees.
//  
//   
//  Example 1:
//  
//  
//  Input: root = [2,1,3]
//  Output: true
//  
//  Example 2:
//  
//  
//  Input: root = [5,1,4,null,null,3,6]
//  Output: false
//  Explanation: The root node's value is 5 but its right child's value is 4.
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [1, 104].
//  -231 <= Node.val <= 231 - 1
//  
//  

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, nullptr, nullptr);
    }

    bool helper(TreeNode* node, TreeNode* low, TreeNode* high) {
        if (node == nullptr) {
            return true;
        }

        if ((low && node->val <= low->val) || (high && node->val >= high->val)) {
            return false;
        } 

        return helper(node->left, low, node) && helper(node->right, node, high);

    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> st;
        TreeNode* node = root;
        TreeNode* v = nullptr;
        while (st.size() > 0 || node) {
            while (node) {
                st.push(node);
                node = node->left;
            }

            node = st.top();
            st.pop();
            if (v && v->val >= node->val) {
                return false;
            }
            v = node;
            node = node->right;
        }
        return true;
    }
};