//  Tag: Binary Tree, Divide and Conquer, Binary Search Tree, Depth First Search/DFS
//  Time: O(N)
//  Space: O(H)
//  Ref: -
//  Note: InOrder

//  Given a binary search tree and a range `[k1, k2]`, return node values within a given range in ascending order.
//  
//  **Example 1:**  
//   
//  Input:  
//  ``` 
//  tree = {5}
//  k1 = 6
//  k2 = 10
//  ``` 
//  Output:  
//  ``` 
//  []
//  ``` 
//  Explanation:  
//  
//  No number between 6 and 10
//  
//  **Example 2:**  
//   
//  Input:  
//  ``` 
//  tree = {20,8,22,4,12}
//  k1 = 10
//  k2 = 22
//  ``` 
//  Output:  
//  ``` 
//  [12,20,22]
//  ``` 
//  Explanation:  
//  
//  [12,20,22] between 10 and 22
//  
//  

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode *root, int k1, int k2) {
        // write your code here
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *node = root;

        while (st.size() > 0 || node) {
            while (node) {
                if (node->val < k1) {
                    node = node->right;
                } else {
                    st.push(node);
                    node = node->left;
                }
            }

            if (st.size() > 0) {
                node = st.top();
                st.pop();

                if (node->val > k2) {
                    break;
                }

                if (node->val >= k1) {
                    res.push_back(node->val);
                }

                node = node->right;
            } 
        }
  
        return res;
    }

};

class Solution {
public:
    /**
     * @param root: param root: The root of the binary search tree
     * @param k1: An integer
     * @param k2: An integer
     * @return: return: Return all keys that k1<=key<=k2 in ascending order
     */
    vector<int> searchRange(TreeNode *root, int k1, int k2) {
        // write your code here
        vector<int> res;
        helper(root, k1, k2, res);
        return res;
    }

    void helper(TreeNode *node, int low, int high, vector<int>& res) {
        if (node == nullptr) {
            return;
        }

        if (node->val > low) {
            helper(node->left, low, high, res);
        }
        if (node->val >= low && node->val <= high) {
            res.push_back(node->val);
        }
        if (node->val < high) {
            helper(node->right, low, high, res);
        }
    }
};