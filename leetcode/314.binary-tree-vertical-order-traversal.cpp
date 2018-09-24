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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        if (root == NULL)
        {
            return vector<vector<int>>();
        }

        unordered_map<int, vector<int>> columnsMap;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        int min_col = 0;
        int max_col = 0;

        //cal calculate col for each node
        while(!q.empty())
        {
            int size = q.size();
            for (auto i = 0; i < size; ++i)
            {
                TreeNode* node = q.front().first;
                int col = q.front().second;
                q.pop();

                columnsMap[col].push_back(node->val);
                
                if (node->left)
                {
                    min_col = min(min_col, col - 1);
                    q.push(make_pair(node->left, col - 1));
                }

                if (node->right)
                {
                    max_col = max(max_col, col + 1);
                    q.push(make_pair(node->right, col + 1));
                }
            }
        }

        vector<vector<int>> res;
        for (auto i = min_col; i <= max_col; ++i)
        {
            res.push_back(columnsMap[i]);
        }

        return res;
    }
};
