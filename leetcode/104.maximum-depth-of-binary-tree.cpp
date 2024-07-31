//  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(Height)
//  Ref: -
//  Note: Recursion

//  Given the root of a binary tree, return its maximum depth.
//  A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//   
//  Example 1:
//  
//  
//  Input: root = [3,9,20,null,null,15,7]
//  Output: 3
//  
//  Example 2:
//  
//  Input: root = [1,null,2]
//  Output: 2
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [0, 104].
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int height = 0;
        deque<TreeNode *> queue;
        queue.push_back(root);
        
        while (queue.size() > 0) {
            height += 1;
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = queue.front();
                queue.pop_front();
                if (node->left) {
                    queue.push_back(node->left);
                }
                if (node->right) {
                    queue.push_back(node->right);
                }
            }
        }

        return height;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};