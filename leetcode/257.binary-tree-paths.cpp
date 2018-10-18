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
    void dfs(TreeNode * cur, string path, vector<string>& ans)
    {
        path += to_string(cur->val);
        
        if (cur->left == NULL && cur->right == NULL)
        {
            ans.push_back(path);
            return;
        }
        
        if (cur->left)
        {
            dfs(cur->left, path + "->", ans);
        }
        
        if (cur->right)
        {
            dfs(cur->right, path + "->", ans);
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)
        {
            return vector<string>();
        }
        
        vector<string> ans;
        dfs(root, "", ans);
        
        return ans;        
    }
};