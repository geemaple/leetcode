//  Tag: Tree, Depth-First Search, String, Backtracking, Binary Tree
//  Time: O(N)
//  Space: O(Height)
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
        if (root == nullptr) {
            return vector<string>{};
        }

        vector<string> results;
        string path = "";
        helper(root, path, results);
        return results;
    }

    void helper(TreeNode* node, string path, vector<string> &results) {
        path += to_string(node->val);
        if (node->left == nullptr and node->right == nullptr) {
            results.push_back(path);
            return;
        }

        if (node->left) {
            helper(node->left, path + "->", results);
        }

        if (node->right) {
            helper(node->right, path + "->", results);
        }
    }
};