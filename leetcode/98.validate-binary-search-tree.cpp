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
    bool isValidBST(TreeNode *node, TreeNode *minNode, TreeNode *maxNode){
        if (node == NULL)
        {
            return true;
        }
        
        if ((minNode && node->val <= minNode->val) || (maxNode && node->val >= maxNode->val))
        {
            return false;
        }
        
        return isValidBST(node->left, minNode, node) && isValidBST(node->right, node, maxNode);
    }
    
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
    
public:
    // inorder traversal
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    
    // divide and conquer
    bool isValidBST2(TreeNode* root) {
        return isValidBST(root, NULL, NULL);
    }
};
