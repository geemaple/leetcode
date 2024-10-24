//  Tag: Tree, Depth-First Search, Binary Search Tree, Binary Tree
//  Time: O(K)
//  Space: O(H)
//  Ref: -
//  Note: -

//  Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
//   
//  Example 1:
//  
//  
//  Input: root = [3,1,4,null,2], k = 1
//  Output: 1
//  
//  Example 2:
//  
//  
//  Input: root = [5,3,6,2,4,null,null,1], k = 3
//  Output: 3
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is n.
//  1 <= k <= n <= 104
//  0 <= Node.val <= 104
//  
//   
//  Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
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
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *cur = root;
        stack<TreeNode *> st;
        int count = 0;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            st.pop();
            count++;

            if (count == k) {
                return cur->val;
            }

            cur = cur->right;
        }

        return -1;
    }   
};

// follow-up
struct TreeNode {
    int val;
    int size;  // size of the subtree rooted at this node
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), size(1), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int leftSize = getSize(root->left);

        if (k <= leftSize) {
            return kthSmallest(root->left, k);
        } else if (k == leftSize + 1) {
            return root->val;
        } else {
            return kthSmallest(root->right, k - leftSize - 1);
        }
    }

    int getSize(TreeNode* node) {
        return node ? node->size : 0;
    }
}