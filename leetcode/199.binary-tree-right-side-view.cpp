//  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(W)
//  Ref: -
//  Note: -

//  Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//   
//  Example 1:
//  
//  
//  Input: root = [1,2,3,null,5,null,4]
//  Output: [1,3,4]
//  
//  Example 2:
//  
//  Input: root = [1,null,3]
//  Output: [1,3]
//  
//  Example 3:
//  
//  Input: root = []
//  Output: []
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [0, 100].
//  -100 <= Node.val <= 100
//  
//  

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return vector<int>{};
        }

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                if (i == size - 1) {
                    res.push_back(cur->val);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root, 1, res);
        return res;
    }

    void helper(TreeNode *cur, int level, vector<int> &res) {
        if (!cur) {
            return;
        }

        if (res.size() < level) {
            res.push_back(cur->val);
        }

        helper(cur->right, level + 1, res);
        helper(cur->left, level + 1, res);
    }
};