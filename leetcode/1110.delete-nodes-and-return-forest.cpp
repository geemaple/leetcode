//  Tag: Array, Hash Table, Tree, Depth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given the root of a binary tree, each node in the tree has a distinct value.
//  After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
//  Return the roots of the trees in the remaining forest. You may return the result in any order.
//   
//  Example 1:
//  
//  
//  Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
//  Output: [[1,2,null,4],[6],[7]]
//  
//  Example 2:
//  
//  Input: root = [1,2,4,null,3], to_delete = [3]
//  Output: [[1,2,4]]
//  
//   
//  Constraints:
//  
//  The number of nodes in the given tree is at most 1000.
//  Each node has a distinct value between 1 and 1000.
//  to_delete.length <= 1000
//  to_delete contains distinct values between 1 and 1000.
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> set(to_delete.begin(), to_delete.end());
        vector<TreeNode *> res;
        root = helper(root, set, res);
        if (root) {
            res.push_back(root);
        }

        return res;
    }

    TreeNode* helper(TreeNode *node, unordered_set<int> &to_delete, vector<TreeNode *> &res) {
        if (!node) {
            return nullptr;
        }

        node->left = helper(node->left, to_delete, res);
        node->right = helper(node->right, to_delete, res);

        if (to_delete.count(node->val)) {
            if (node->left) {
                res.push_back(node->left);
            }
            if (node->right) {
                res.push_back(node->right);
            }

            return nullptr;
        }

        return node;
    }
};