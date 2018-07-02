/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (root == NULL)
        {
            return vector<vector<int>>();
        }
        
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            vector<int> level;
            for (auto i = 0; i < n; ++i)
            {
                // add value to level
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            res.push_back(level);
        }
        
        return res;
    }
};
