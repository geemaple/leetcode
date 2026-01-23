//  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
//  Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
//   
//  Example 1:
//  
//  
//  Input: root = [1,7,0,7,-8,null,null]
//  Output: 2
//  Explanation: 
//  Level 1 sum = 1.
//  Level 2 sum = 7 + 0 = 7.
//  Level 3 sum = 7 + -8 = -1.
//  So we return the level with the maximum sum which is level 2.
//  
//  Example 2:
//  
//  Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
//  Output: 2
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [1, 104].
//  -105 <= Node.val <= 105
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
    int maxLevelSum(TreeNode* root) {
        int res = root->val;
        int max_level = 1;
        int level = 1;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int total = 0;
            for (int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                q.pop();
                total += cur->val;
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            if (total > res) {
                res = total;
                max_level = level;
            }
            level += 1;
        }


        return max_level;

    }
};