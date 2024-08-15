//  Tag: Tree, Depth-First Search, String Matching, Binary Tree, Hash Function
//  Time: O(NM)
//  Space: O(H)
//  Ref: -
//  Note: -

//  Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
//  A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
//   
//  Example 1:
//  
//  
//  Input: root = [3,4,5,1,2], subRoot = [4,1,2]
//  Output: true
//  
//  Example 2:
//  
//  
//  Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
//  Output: false
//  
//   
//  Constraints:
//  
//  The number of nodes in the root tree is in the range [1, 2000].
//  The number of nodes in the subRoot tree is in the range [1, 1000].
//  -104 <= root.val <= 104
//  -104 <= subRoot.val <= 104
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }

        if (isEqual(root, subRoot)) {
            return true;
        } else {
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    }

    bool isEqual(TreeNode* n1, TreeNode* n2) {
        if (!n1 && !n2) {
            return true;
        }

        if (!n1 || !n2 || n1->val != n2->val) {
            return false;
        }

        return isEqual(n1->left, n2->left) && isEqual(n1->right, n2->right);

    }
};