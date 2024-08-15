//  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(W)
//  Ref: -
//  Note: -

//  Given the root of a binary tree, return the leftmost value in the last row of the tree.
//   
//  Example 1:
//  
//  
//  Input: root = [2,1,3]
//  Output: 1
//  
//  Example 2:
//  
//  
//  Input: root = [1,2,3,4,null,5,6,null,null,7]
//  Output: 7
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [1, 104].
//  -231 <= Node.val <= 231 - 1
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            int n = q.size();
            res = q.front()->val;
            for (int i = 0; i < n; i++) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }

                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }

        return res;
    }
};