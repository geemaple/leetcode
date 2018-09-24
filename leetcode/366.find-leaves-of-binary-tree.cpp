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
    unordered_map<int, vector<int>> heightMap;
    int nodeHeight(TreeNode* node)
    {
        if (node == NULL)
        {
            return 0;
        }

        int height = max(nodeHeight(node->left) + 1, nodeHeight(node->right) + 1);
        heightMap[height].push_back(node->val);

        return height;
    }

public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        int max_height = nodeHeight(root);

        vector<vector<int>> res;
        for(auto i = 1; i <= max_height; ++i)
        {
            res.push_back(heightMap[i]);
        }

        return res;
    }
};
