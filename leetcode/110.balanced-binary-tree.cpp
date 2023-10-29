//  Category: Tree, Depth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(Height)
//  Ref: -
//  Note: Recursion

//  Given a binary tree, determine if it is height-balanced.
//   
//  Example 1:
//  
//  
//  Input: root = [3,9,20,null,null,15,7]
//  Output: true
//  
//  Example 2:
//  
//  
//  Input: root = [1,2,2,3,3,null,null,4,4]
//  Output: false
//  
//  Example 3:
//  
//  Input: root = []
//  Output: true
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [0, 5000].
//  -104 <= Node.val <= 104
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
    bool isBalanced(TreeNode* root) {
        return helper(root) != -1;
    }

    int helper(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int left = helper(node->left);
        int right = helper(node->right);
        if (left == -1 || right == -1) {
            return -1;
        }

        return abs(left - right) > 1 ? -1 : max(left, right) + 1;
    }
};