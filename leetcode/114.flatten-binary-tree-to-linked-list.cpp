//  Tag: Stack, Tree, Depth-First Search, Linked List, Binary Tree
//  Time: O(N)
//  Space: O(H)
//  Ref: -
//  Note: PreOrder

//  Given the root of a binary tree, flatten the tree into a "linked list":
//  
//  The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
//  The "linked list" should be in the same order as a pre-order traversal of the binary tree.
//  
//   
//  Example 1:
//  
//  
//  Input: root = [1,2,5,3,4,null,6]
//  Output: [1,null,2,null,3,null,4,null,5,null,6]
//  
//  Example 2:
//  
//  Input: root = []
//  Output: []
//  
//  Example 3:
//  
//  Input: root = [0]
//  Output: [0]
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [0, 2000].
//  -100 <= Node.val <= 100
//  
//   
//  Follow up: Can you flatten the tree in-place (with O(1) extra space)?

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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        TreeNode *last = nullptr;
        stack<TreeNode *> st;
        st.push(root);

        while (st.size() > 0) {
            TreeNode *node = st.top();
            st.pop();

            if (last) {
                last->right = node;
                last->left = nullptr;
            }

            last = node;

            if (node->right) {
                st.push(node->right);
            }

            if (node->left) {
                st.push(node->left);
            }
        }
    }
};

class Solution {
private:
public:
    TreeNode *pre = nullptr;
    void helper(TreeNode *cur) {
        if (cur == nullptr) {
            return;
        }
        
        TreeNode *left = cur->left;
        TreeNode *right = cur->right;
        
        if (pre) {
            pre->right = cur;
        }
        cur->left = nullptr;
        pre = cur;
        
        helper(left);
        helper(right);
    }
    
    void flatten(TreeNode* root) {
        helper(root);
    }
};