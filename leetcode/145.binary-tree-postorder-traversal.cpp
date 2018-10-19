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
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == NULL)
        {
            return vector<int>();
        }
        
        vector<int> res;
        stack<TreeNode*> st;
        
        TreeNode* cur = root;
        TreeNode* last = NULL;
        
        while(cur || !st.empty())
        {
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            
            TreeNode *peek = st.top();
            if (peek->right && last != peek->right)
            {
                cur = peek->right;
            }
            else
            {
                res.push_back(peek->val);
                last = peek;
                st.pop();
            }
        }
        
        return res;
    }
};