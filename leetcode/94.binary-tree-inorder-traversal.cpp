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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
        {
            return vector<int>();
        }
        
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        
        while (!st.empty() || cur) {
            
            while(cur)
            {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();
            res.push_back(cur->val);

            cur = cur->right;
        }
        
        return res;
    }
};
