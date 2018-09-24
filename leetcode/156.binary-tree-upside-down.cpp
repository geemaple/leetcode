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
    TreeNode *newRoot = NULL;

    void invert(TreeNode *cur)
    {
        if (cur == NULL)
        {
            return;
        }

        if (cur->left == NULL)
        {
            newRoot = cur;
        }
        else
        {
            invert(cur->left);
            cur->left->left = cur->right;
            cur->left->right = cur;
            cur->left = NULL;
            cur->right = NULL;
        }
    }
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        invert(root);
        return newRoot;
    }
};
