/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// inorder traversal
class Solution {
private:    
    TreeNode* prev = NULL;
    
    bool validate(TreeNode* node) {
        if (node == NULL) return true;
        if (!validate(node->left)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return validate(root);
    }
};

// divide and conquer
class Solution2 {
private:
    bool helper(TreeNode* cur, TreeNode* minNode, TreeNode* maxNode)
    {
        if (cur == NULL)
        {
            return true;
        }
        
        if ((minNode && minNode->val >= cur->val) || (maxNode && maxNode->val <= cur->val))
        {
            return false;
        }
        
        return helper(cur->left, minNode, cur) && helper(cur->right, cur, maxNode);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};
