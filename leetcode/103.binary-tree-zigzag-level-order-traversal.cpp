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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL)
        {
            return vector<vector<int>>();
        }

        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> res;
        bool reversed = false;

        while (!q.empty())
        {
            vector<int> ans;

            int size = q.size();
            for (auto i = 0; i < size; ++i)
            {
                TreeNode *tmp = q.front();
                q.pop();

                ans.push_back(tmp->val);

                if (tmp->left)
                {
                    q.push(tmp->left);
                }
                
                if (tmp->right)
                {
                    q.push(tmp->right);
                }
            }

            if (reversed)
            {
                reverse(ans.begin(), ans.end());
            }

            res.push_back(ans);
            reversed = !reversed;
        }

        return res;
    }
};
