//  Tag: Tree, Depth-First Search, Breadth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(W)
//  Ref: -
//  Note: -

//  Given a binary tree, find its minimum depth.
//  The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//  Note: A leaf is a node with no children.
//   
//  Example 1:
//  
//  
//  Input: root = [3,9,20,null,null,15,7]
//  Output: 2
//  
//  Example 2:
//  
//  Input: root = [2,null,3,null,4,null,5,null,6]
//  Output: 5
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [0, 105].
//  -1000 <= Node.val <= 1000
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
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        if (!root->left) {
            return minDepth(root->right) + 1;
        } 

        if (!root->right) {
            return minDepth(root->left) + 1;
        }

        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int count = q.size();
            level++;
            for (int i = 0; i < count; i++) {
                TreeNode *cur = q.front();
                q.pop();
                if (!cur->left && !cur->right) {
                    return level;
                }

                if (cur->left) {
                    q.push(cur->left);
                }

                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return -1;
    }
};