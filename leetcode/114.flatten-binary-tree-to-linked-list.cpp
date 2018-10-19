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
private:
    TreeNode *pre = NULL;
    void helper(TreeNode *cur)
    {
        if (cur == NULL)
        {
            return;
        }
        
        TreeNode *left = cur->left;
        TreeNode *right = cur->right;
        
        if (pre)
        {
            pre->right = cur;
        }
        cur->left = NULL;
        pre = cur;
        
        helper(left);
        helper(right);
    }
public:
    void flatten(TreeNode* root) {
        helper(root);
    }
};