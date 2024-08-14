//  Tag: Tree, Depth-First Search, Binary Search Tree, Binary Tree
//  Time: O(N)
//  Space: O(H)
//  Ref: -
//  Note: -

//  You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.
//   
//  Example 1:
//  
//  
//  Input: root = [1,3,null,null,2]
//  Output: [3,1,null,null,2]
//  Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
//  
//  Example 2:
//  
//  
//  Input: root = [3,1,4,null,null,2]
//  Output: [2,1,4,null,null,3]
//  Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [2, 1000].
//  -231 <= Node.val <= 231 - 1
//  
//   
//  Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?

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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        inorder(root, pre, first, second);
        swap(first->val, second->val);
    }

    void inorder(TreeNode* node,  TreeNode* &pre, TreeNode* &first, TreeNode* &second) {
        if (!node) {
            return;
        }

        inorder(node->left, pre, first, second);
        if (pre && pre->val > node->val) {
            if (!first) {
                first = pre;
            }
            second = node;
        }
        pre = node;
        inorder(node->right, pre, first, second);
    }
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* pre = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        stack<TreeNode *> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();

            if (pre && pre->val > cur->val) {
                if (!first) {
                    first = pre;
                }
                second = cur;
            }
            pre = cur;
            cur = cur->right;
        }
        swap(first->val, second->val);
    }
};