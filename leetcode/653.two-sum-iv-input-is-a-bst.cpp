//  Tag: Hash Table, Two Pointers, Tree, Depth-First Search, Breadth-First Search, Binary Search Tree, Binary Tree
//  Time: O(NH)
//  Space: O(H)
//  Ref: -
//  Note: -

//  Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.
//   
//  Example 1:
//  
//  
//  Input: root = [5,3,6,2,4,null,7], k = 9
//  Output: true
//  
//  Example 2:
//  
//  
//  Input: root = [5,3,6,2,4,null,7], k = 28
//  Output: false
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [1, 104].
//  -104 <= Node.val <= 104
//  root is guaranteed to be a valid binary search tree.
//  -105 <= k <= 105
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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            TreeNode *target = find(root, k - cur->val);
            if (target && target != cur) {
                return true;
            }

            if (cur->right) {
                st.push(cur->right);
            }

            if (cur->left) {
                st.push(cur->left);
            }

        }

        return false;
    }

    TreeNode* find(TreeNode* root, int k) {
        if (!root){
            return nullptr;
        }

        if (root->val == k) {
            return root;
        }

        if (root->val < k) {
            return find(root->right, k);
        } else {
            return find(root->left, k);
        }

    }
};