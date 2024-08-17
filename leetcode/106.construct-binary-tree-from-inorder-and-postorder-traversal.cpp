//  Tag: Array, Hash Table, Divide and Conquer, Tree, Binary Tree
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
//   
//  Example 1:
//  
//  
//  Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
//  Output: [3,9,20,null,null,15,7]
//  
//  Example 2:
//  
//  Input: inorder = [-1], postorder = [-1]
//  Output: [-1]
//  
//   
//  Constraints:
//  
//  1 <= inorder.length <= 3000
//  postorder.length == inorder.length
//  -3000 <= inorder[i], postorder[i] <= 3000
//  inorder and postorder consist of unique values.
//  Each value of postorder also appears in inorder.
//  inorder is guaranteed to be the inorder traversal of the tree.
//  postorder is guaranteed to be the postorder traversal of the tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorder_map;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inorder_map[inorder[i]] = i;
        }
        return helper(inorder_map, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* helper(unordered_map<int, int>& inorder_map, vector<int>& postorder, int s0, int e0, int s1, int e1) {
        if (s1 > e1) {
            return nullptr;
        }

        int val = postorder[e1];
        TreeNode *root = new TreeNode(val);
        if (s1 < e1) {
            int mid = inorder_map[val];
            int left_size = mid - s0;
            root->left = helper(inorder_map, postorder, s0, mid - 1, s1, left_size + s1 - 1);
            root->right = helper(inorder_map, postorder, mid + 1, e0, left_size + s1, e1 - 1);
        }

        return root;
    }
};