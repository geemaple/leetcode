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
    int ans = 0;
    
    int helper(TreeNode* cur)
    {
        if (cur == NULL)
        {
            return 0;
        }
        
        int left = helper(cur->left);
        int right = helper(cur->right);
        
        left = (cur->left && cur->left->val == cur->val) ? left + 1 : 0;
        right = (cur->right && cur->right->val == cur->val) ? right + 1 : 0;
        
        ans = max(ans, left + right);
        
        return max(left, right);
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        helper(root);
        return ans;
    }
};