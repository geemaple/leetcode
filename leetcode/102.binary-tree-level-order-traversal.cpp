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
        
        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans;
            for (auto i = 0; i < size; ++i)
            {
                TreeNode *tmp = q.front();
                q.pop();
                ans.push_back(tmp->val);
                
                if (tmp->left)
                {
                    q.push(tmp->left);
                }
                
                if (tmp->right)
                {
                    q.push(tmp->right);
                }
            }
            
            res.push_back(ans);
        }
        
        return res;
    }
};