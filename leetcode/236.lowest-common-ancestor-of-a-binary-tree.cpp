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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
        {
            return NULL;
        }
        
        if (root->val == p->val || root->val == q->val)
        {
            return root;
        }
        
        TreeNode *leftAncestor = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightAncestor = lowestCommonAncestor(root->right, p, q);
        
        if (leftAncestor && rightAncestor)
        {
            return root;
        }
        
        if (leftAncestor)
        {
            return leftAncestor;
        }
        
        if (rightAncestor)
        {
            return rightAncestor;
        }
        
        return NULL;
    }
};
