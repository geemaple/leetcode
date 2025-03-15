//  Tag: Dynamic Programming, Tree, Depth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
//  Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
//  Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
//   
//  Example 1:
//  
//  
//  Input: root = [3,2,3,null,3,null,1]
//  Output: 7
//  Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//  
//  Example 2:
//  
//  
//  Input: root = [3,4,5,1,3,null,1]
//  Output: 9
//  Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [1, 104].
//  0 <= Node.val <= 104
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
    int rob(TreeNode* root) {
        pair<int, int> res = helper(root);
        return max(res.first, res.second);
    }

    pair<int, int> helper(TreeNode *node) {
        if (!node) {
            return make_pair(0, 0);
        }

        pair<int, int> left = helper(node->left);
        pair<int, int> right = helper(node->right);
        int rob = node->val + left.second + right.second;
        int not_rob = max(left.first, left.second) + max(right.first, right.second);

        return make_pair(rob, not_rob);
    }
};

class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode *, int> cache;
        return helper(root, cache);
    }

 int helper(TreeNode* node, unordered_map<TreeNode*, int>& cache) {
        if (!node) {
            return 0; 
        }

        if (cache.find(node) == cache.end()) {
            int rob = node->val;
            if (node->left) {
                rob += helper(node->left->left, cache) + helper(node->left->right, cache);
            }
            if (node->right) {
                rob += helper(node->right->left, cache) + helper(node->right->right, cache);
            }

            int notRob = helper(node->left, cache) + helper(node->right, cache);
            cache[node] = max(rob, notRob);
        }
        return cache[node];
    }
};