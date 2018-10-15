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
    int closestValue(TreeNode* root, double target) {
        TreeNode *cur = root;
        int closest = cur->val;
        
        while (cur)
        {
            if (abs(closest - target) > abs(cur->val - target))
            {
                closest = cur->val;
            }
            
            if (cur->val - target > 0)
            {
                cur = cur->left;
            }
            else
            {
                cur = cur->right;
            }
        }
        
        return closest;
    }
};