//  Tag: Stack, Tree, Depth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(H)
//  Ref: -
//  Note: PostOrder

//  Given the root of a binary tree, return the postorder traversal of its nodes' values.
//   
//  Example 1:
//  
//  
//  Input: root = [1,null,2,3]
//  Output: [3,2,1]
//  
//  Example 2:
//  
//  Input: root = []
//  Output: []
//  
//  Example 3:
//  
//  Input: root = [1]
//  Output: [1]
//  
//   
//  Constraints:
//  
//  The number of the nodes in the tree is in the range [0, 100].
//  -100 <= Node.val <= 100
//  
//   
//  Follow up: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
        helper(root, results);
        return results;
    }

    void helper(TreeNode *node, vector<int> &results) {
        if (node == nullptr) {
            return;
        }
        
        helper(node->left, results);
        helper(node->right, results);
        results.push_back(node->val);
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode *> st;
        vector<int> res;
        TreeNode *cur = root;
        TreeNode *pre = nullptr;
        while (cur || !st.empty()) {
            while (cur) {
                st.push(cur);
                cur = cur->left;
            }

            cur = st.top();
            if (cur->right && cur->right != pre) {
                cur = cur->right;
            } else {
                st.pop();
                res.push_back(cur->val);
                pre = cur;
                cur = nullptr;
            }
        }
        return res;
    }
};