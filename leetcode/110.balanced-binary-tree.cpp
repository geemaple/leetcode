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
    int treeDepth(TreeNode *node){
        if (node == NULL)
        {
            return 0;
        }
        
        int left = treeDepth(node->left);
        int right = treeDepth(node->right);
        
        if (left == -1 || right == -1)
        {
            return -1;
        }
        
        if (abs(left - right) > 1)
        {
            return -1;
        }
        
        return max(left, right) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        return treeDepth(root) != -1;
    }
};
