//  Category: Stack, Tree, Depth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(Height)
//  Ref: -
//  Note: PreOrder

//  Given the root of a binary tree, return the preorder traversal of its nodes' values.
//   
//  Example 1:
//  
//  
//  Input: root = [1,null,2,3]
//  Output: [1,2,3]
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> results;
        helper(root, results);
        return results;
    }

    void helper(TreeNode *node, vector<int> &results) {
        if (node == nullptr) {
            return;
        }

        results.push_back(node->val);
        helper(node->left, results);
        helper(node->right, results);
    }
};


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        } 

        vector<int> results;
        stack<TreeNode *> stack;
        stack.push(root);

        while (stack.size() > 0) {
            TreeNode *node = stack.top();
            stack.pop();
            results.push_back(node->val);

            if (node->right) {
                stack.push(node->right);
            }

            if (node->left) {
                stack.push(node->left);
            }
        }
        
        return results;
    }
};