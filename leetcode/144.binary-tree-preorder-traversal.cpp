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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL)
        {
            return vector<int>();
        }
        
        vector<int> res;
        stack<TreeNode *> s;
        s.push(root);
        
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            
            res.push_back(node->val);
            
            if (node->right)
            {
                s.push(node->right);
            }
            
            if (node->left)
            {
                s.push(node->left);
            }
        }
        
        return res;
    }
};

class Solution2 {
private:
    void helper(TreeNode* node, vector<int> &result){
        if (node == NULL)
        {
            return;
        }
        
        result.push_back(node->val);
        helper(node->left, result);
        helper(node->right, result);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};
