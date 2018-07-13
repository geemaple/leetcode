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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
        {
            return vector<int>();
        }
        
        vector<int> res;
        stack<TreeNode *> s;
        TreeNode *node = root;
        
        while (!s.empty() || node) {
            
            if (node)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                node = s.top();
                s.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        
        return res;
    }
};
