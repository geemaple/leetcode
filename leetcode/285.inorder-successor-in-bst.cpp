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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL)
        {
            return NULL;
        }

        TreeNode* ans = NULL;
        TreeNode* cur = root;
        while(cur->val != p->val)
        {
            if (cur->val < p->val)
            {
                cur = cur->right;
            }

            if (cur->val > p->val)
            {
                ans = cur;
                cur = cur->left;
            }
        }

        if (p->right)
        {
            cur = p->right;
            while(cur->left)
            {
                cur = cur->left;
            }

            ans = cur;
        }

        return ans;
    }
};
