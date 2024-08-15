//  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Search Tree, Binary Tree
//  Time: O(N)
//  Space: O(H)
//  Ref: -
//  Note: -

//  Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.
//   
//  Example 1:
//  
//  
//  Input: root = [4,2,6,1,3]
//  Output: 1
//  
//  Example 2:
//  
//  
//  Input: root = [1,0,48,null,null,12,49]
//  Output: 1
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [2, 104].
//  0 <= Node.val <= 105
//  
//   
//  Note: This question is the same as 783: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    int res = INT_MAX;
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        helper(root); 
        return res;
    }

    void helper(TreeNode* node) {
        if (!node) {
            return;
        }

        helper(node->left);

        if (pre) {
            res = min(res, abs(pre->val - node->val));
        }
        pre = node;
        helper(node->right);
    }
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        return helper(root, nullptr, INT_MAX).second; 
    }

    pair<TreeNode *, int> helper(TreeNode* node, TreeNode*pre, int res) {
        if (!node) {
            return make_pair(pre, res);
        }

        auto tmp = helper(node->left, pre, res);
        pre = tmp.first;
        res = tmp.second;

        if (pre) {
            res = min(res, abs(pre->val - node->val));
        }
        pre = node;
        return helper(node->right, pre, res);
    }
};