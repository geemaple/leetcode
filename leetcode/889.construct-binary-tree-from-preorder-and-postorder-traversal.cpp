//  Tag: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
//  If there exist multiple answers, you can return any of them.
//   
//  Example 1:
//  
//  
//  Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
//  Output: [1,2,3,4,5,6,7]
//  
//  Example 2:
//  
//  Input: preorder = [1], postorder = [1]
//  Output: [1]
//  
//   
//  Constraints:
//  
//  1 <= preorder.length <= 30
//  1 <= preorder[i] <= preorder.length
//  All the values of preorder are unique.
//  postorder.length == preorder.length
//  1 <= postorder[i] <= postorder.length
//  All the values of postorder are unique.
//  It is guaranteed that preorder and postorder are the preorder traversal and postorder traversal of the same binary tree.
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int> postorder_map;
        int n = postorder.size();
        for (int i = 0; i < n; i++) {
            postorder_map[postorder[i]] = i;
        }

        return helper(preorder, postorder_map, 0, n - 1, 0, n - 1);
    }

    TreeNode* helper(vector<int>& preorder, unordered_map<int, int>& postorder_map, int s0, int e0, int s1, int e1) {
        if (s0 > e0) {
            return nullptr;
        }

        int val = preorder[s0];
        TreeNode *root = new TreeNode(val);
        if (s0 < e0) {
            int left = preorder[s0 + 1];
            int index = postorder_map[left];
            int left_size = index - s1 + 1;
            root->left = helper(preorder, postorder_map, s0 + 1, s0 + left_size, s1, index);
            root->right = helper(preorder, postorder_map, s0 + left_size + 1, e0, index + 1, e1 - 1);
        }
        return root;
    }
};