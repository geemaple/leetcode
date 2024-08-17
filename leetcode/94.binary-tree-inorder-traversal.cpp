//  Tag: Stack, Tree, Depth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(H)
//  Ref: -
//  Note: InOrder

//  Given the root of a binary tree, return the inorder traversal of its nodes' values.
//   
//  Example 1:
//  
//  
//  Input: root = [1,null,2,3]
//  Output: [1,3,2]
//  
//  Example 2:
//  
//  Input: root = []
//  Output: []
//  
//  Example 3:
//  
//  Input: root = [1]
//  Output: [1]
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [0, 100].
//  -100 <= Node.val <= 100
//  
//   
//  Follow up: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> results;
        helper(root, results);
        return results;
    }

    void helper(TreeNode *node, vector<int> &results) {
        if (node == nullptr) {
            return;
        }

        helper(node->left, results);
        results.push_back(node->val);
        helper(node->right, results);
    }
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> res;
        TreeNode *cur = root;
        stack<TreeNode *> st;

        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }
  
            cur = st.top();
            st.pop();

            res.push_back(cur->val);

            cur = cur->right;
        }
        return res;
    }
};