//  Tag: Hash Table, Tree, Depth-First Search, Breadth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
//  You can return the answer in any order.
//   
//  Example 1:
//  
//  
//  Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
//  Output: [7,4,1]
//  Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
//  
//  Example 2:
//  
//  Input: root = [1], target = 1, k = 3
//  Output: []
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [1, 500].
//  0 <= Node.val <= 500
//  All the values Node.val are unique.
//  target is the value of one of the nodes in the tree.
//  0 <= k <= 1000
//  
//  

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> graph;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();

            if (cur->left) {
                graph[cur->val].push_back(cur->left->val);
                graph[cur->left->val].push_back(cur->val);
                q.push(cur->left);
            }

            if (cur->right) {
                graph[cur->val].push_back(cur->right->val);
                graph[cur->right->val].push_back(cur->val);
                q.push(cur->right);
            }
        }

        return search(graph, target->val, k);
    }

    vector<int> search(unordered_map<int, vector<int>> &graph, int target, int k) {
        vector<int> res;
        unordered_set<int> visited;
        queue<int> q;
        q.push(target);
        visited.insert(target);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int cur = q.front();
                q.pop();
                if (level == k) {
                    res.push_back(cur);
                } else {
                    for (int child: graph[cur]) {
                        if (visited.count(child) == 0) {
                            visited.insert(child);
                            q.push(child);
                        }
                    }
                }
            }
            level += 1;
        }

        return res;
    }
};