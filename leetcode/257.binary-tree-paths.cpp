//  Tag: String, Backtracking, Tree, Depth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(H)
//  Ref: -
//  Note: -

//  Given the root of a binary tree, return all root-to-leaf paths in any order.
//  A leaf is a node with no children.
//   
//  Example 1:
//  
//  
//  Input: root = [1,2,3,null,5]
//  Output: ["1->2->5","1->3"]
//  
//  Example 2:
//  
//  Input: root = [1]
//  Output: ["1"]
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [1, 100].
//  -100 <= Node.val <= 100
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, to_string(root->val), res);
        return res;
    }

    void dfs(TreeNode* node, string tmp, vector<string> &res) {
        if (!node->left && !node->right) {
            res.push_back(tmp);
            return;
        }

        vector<TreeNode *> children = {node->left, node->right};
        for (auto child: children) {
            if (child) {
                dfs(child, tmp + "->" + to_string(child->val), res);
            }
        }
    }
};