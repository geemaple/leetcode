//  Tag: Binary Tree, Depth First Search/DFS, Divide and Conquer
//  Time: O(N)
//  Space: O(N)
//  Ref: Leetcode-366
//  Note: -

//  Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
//  
//  **Example1**
//  Input: {1,2,3,4,5}
//  Output:  `[[4, 5, 3], [2], [1]]`.
//  Explanation:
//  ```
//      1
//     / \
//    2   3
//   / \     
//  4   5    
//  ```
//  
//  **Example2**
//  Input: {1,2,3,4}
//  Output:  `[[4, 3], [2], [1]]`.
//  Explanation:
//  ```
//      1
//     / \
//    2   3
//   /
//  4 
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
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here
        unordered_map<int, vector<int>> cache;
        vector<vector<int>> res;
        findReverseHeight(root, cache);
        int height = 0;
        while (cache.count(height) > 0) {
            res.push_back(cache[height]);
            height += 1;
        }

        return res;
    }

    int findReverseHeight(TreeNode * root, unordered_map<int, vector<int>>& cache) {
        if (!root) {
            return -1;
        }
        
        int lh = findReverseHeight(root->left, cache);
        int rh = findReverseHeight(root->right, cache);
        int height = max(lh, rh) + 1;
        cache[height].push_back(root->val);
        return height;
    }
};

class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @return: collect and remove all leaves
     */
    vector<vector<int>> findLeaves(TreeNode * root) {
        // write your code here
        vector<vector<int>> res;
        findReverseHeight(root, res);
        return res;
    }

    int findReverseHeight(TreeNode * root, vector<vector<int>>& res) {
        if (!root) {
            return -1;
        }
        
        int lh = findReverseHeight(root->left, res);
        int rh = findReverseHeight(root->right, res);
        int height = max(lh, rh) + 1;
        if (height >= res.size()) {
            res.push_back({});
        }
        res[height].push_back(root->val);
        return height;
    }
};