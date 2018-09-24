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
    void inverse_midoder(TreeNode *node){

        if (node == NULL)
        {
            return;
        }

        inverse_midoder(node->right);

        if (pre == NULL)
        {
            pre = node;
        }
        else
        {
            node->val += pre->val;
            pre = node;
        }

        inverse_midoder(node->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        inverse_midoder(root);
        return root;
    }
};
