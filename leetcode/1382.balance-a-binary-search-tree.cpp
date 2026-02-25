//  Tag: Divide and Conquer, Greedy, Tree, Depth-First Search, Binary Search Tree, Binary Tree
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: DSW O(n)|O(1)

//  Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
//  A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
//   
//  Example 1:
//  
//  
//  Input: root = [1,null,2,null,3,null,4,null,null]
//  Output: [2,1,3,null,null,null,4]
//  Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
//  
//  Example 2:
//  
//  
//  Input: root = [2,1,3]
//  Output: [2,1,3]
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [1, 104].
//  1 <= Node.val <= 105
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
    vector<TreeNode*> arr;
    TreeNode* balanceBST(TreeNode* root) {
        arr.clear();
        inorder(root);
        return toBST(0, arr.size() - 1);
    }

        void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);
        arr.push_back(node);
        inorder(node->right);
    }

    TreeNode* toBST(int left, int right) {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;
        TreeNode* root = arr[mid];

        root->left = toBST(left, mid - 1);
        root->right = toBST(mid + 1, right);

        return root;
    }
};