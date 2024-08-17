//  Tag: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
//   
//  Example 1:
//  
//  
//  Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
//  Output: [3,9,20,null,null,15,7]
//  
//  Example 2:
//  
//  Input: preorder = [-1], inorder = [-1]
//  Output: [-1]
//  
//   
//  Constraints:
//  
//  1 <= preorder.length <= 3000
//  inorder.length == preorder.length
//  -3000 <= preorder[i], inorder[i] <= 3000
//  preorder and inorder consist of unique values.
//  Each value of inorder also appears in preorder.
//  preorder is guaranteed to be the preorder traversal of the tree.
//  inorder is guaranteed to be the inorder traversal of the tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inorder_map[inorder[i]] = i;
        }

        return build(preorder, inorder_map, 0, n - 1, 0, n - 1);
    }

    TreeNode* build(vector<int>& preorder, unordered_map<int, int>& inorder_map, int s0, int e0, int s1, int e1) {
        if (s0 > e0) {
            return nullptr;
        }

        int val = preorder[s0];
        TreeNode *node = new TreeNode(val);
        if (s0 < e0) {
            int mid = inorder_map[val];
            int left_size = mid - s1;
            node->left = build(preorder, inorder_map, s0 + 1, left_size + s0, s1, mid - 1);
            node->right = build(preorder, inorder_map, left_size + s0 + 1, e0, mid + 1, e1);
        }

        return node;
    }
};