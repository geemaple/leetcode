//  Tag: Hash Table, Breadth First Search/BFS
//  Time: O(N)
//  Space: O(N)
//  Ref: Leetcode-314
//  Note: -

//  Given a binary tree, return the vertical order traversal of its nodes' values.
//  (ie, from top to bottom, column by column).
//  
//  If two nodes are in the same row and column, the order should be from **left to right**.
//  
//  **For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively.
//  The root of the tree is at (0, 0).**
//  
//  **Example1**
//  ```
//  Inpurt:  {3,9,20,#,#,15,7}
//  Output: [[9],[3,15],[20],[7]]
//  Explanation:
//     3
//    /\
//   /  \
//   9  20
//      /\
//     /  \
//    15   7
//  ```
//  **Example2**
//  ```
//  Input: {3,9,8,4,0,1,7}
//  Output: [[4],[9],[3,0,1],[8],[7]]
//  Explanation:
//       3
//      /\
//     /  \
//     9   8
//    /\  /\
//   /  \/  \
//   4  01   7
//  ```
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
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    vector<vector<int>> verticalOrder(TreeNode *root) {
        // write your code here
        queue<pair<TreeNode *, int>> q;
        unordered_map<int, vector<int>> table;
        q.emplace(root, 0);
        int left = INT_MAX;
        int right = INT_MIN;

        while (!q.empty()) {
            auto [cur, order] = q.front();
            q.pop();
            if (cur) {
                left = min(left, order);
                right = max(right, order);

                table[order].push_back(cur->val);
                q.emplace(cur->left, order - 1);
                q.emplace(cur->right, order + 1);
            }
        }   

        vector<vector<int>> res;
        for (int k = left; k <= right; k++) {
            res.push_back(table[k]);
        }
        return res;
    }
};