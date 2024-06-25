//  Tag: Tree, Breadth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(Width)
//  Ref: -
//  Note: Level

//  Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
//   
//  Example 1:
//  
//  
//  Input: root = [3,9,20,null,null,15,7]
//  Output: [[3],[9,20],[15,7]]
//  
//  Example 2:
//  
//  Input: root = [1]
//  Output: [[1]]
//  
//  Example 3:
//  
//  Input: root = []
//  Output: []
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [0, 2000].
//  -1000 <= Node.val <= 1000
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>{};
        }
        
        vector<vector<int>> res;
        queue<TreeNode*> q; 
        q.push(root);

        while (q.size() > 0) {
            int size = q.size();
            vector<int> level;
            for (auto i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }   
            res.push_back(level);
        }

        return res;
    }
};