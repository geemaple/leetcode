//  Category: Tree, Binary Search Tree, Binary Tree
//  Time: -
//  Space: -
//  Ref: -
//  Note: -

//  Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
//  Basically, the deletion can be divided into two stages:
//  
//  Search for a node to remove.
//  If the node is found, delete the node.
//  
//   
//  Example 1:
//  
//  
//  Input: root = [5,3,6,2,4,null,7], key = 3
//  Output: [5,4,6,2,null,null,7]
//  Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
//  One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
//  Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
//  
//  
//  Example 2:
//  
//  Input: root = [5,3,6,2,4,null,7], key = 0
//  Output: [5,3,6,2,4,null,7]
//  Explanation: The tree does not contain a node with value = 0.
//  
//  Example 3:
//  
//  Input: root = [], key = 0
//  Output: []
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [0, 104].
//  -105 <= Node.val <= 105
//  Each node has a unique value.
//  root is a valid binary search tree.
//  -105 <= key <= 105
//  
//   
//  Follow up: Could you solve it with time complexity O(height of tree)?
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

//TODO:

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) {
                return root;
            }

            TreeNode* parent = nullptr;
            TreeNode* curr = root;

            while (curr) {
                if (key == curr->val) {
                    break;
                }
                parent = curr;

                if (key < curr->val) {
                    curr = curr->left;
                } else {
                    curr = curr->right;
                }
            }

            if (!curr) {
                return root;  // Key not found, nothing to delete
            }

            if (!curr->left) {  // Node has no left child
                if (!parent) {
                    return curr->right;
                }
                if (parent->left == curr) {
                    parent->left = curr->right;
                } else {
                    parent->right = curr->right;
                }
                delete curr;
                return root;
            }

            if (!curr->right) {  // Node has no right child
                if (!parent) {
                    return curr->left;
                }
                if (parent->left == curr) {
                    parent->left = curr->left;
                } else {
                    parent->right = curr->left;
                }
                delete curr;
                return root;
            }

            // Node has two children, find the inorder successor (smallest node in the right subtree)
            TreeNode* successor_parent = curr;
            TreeNode* successor = curr->right;
            while (successor->left) {
                successor_parent = successor;
                successor = successor->left;
            }

            curr->val = successor->val;
            if (successor_parent->left == successor) {
                successor_parent->left = successor->right;
            } else {
                successor_parent->right = successor->right;
            }
            delete successor;

            return root;
    }
};