//  Tag: String, Tree, Depth-First Search, Binary Tree
//  Time: O(N)
//  Space: O(H)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/dcu39zy0Uac

//  We run a preorder depth-first search (DFS) on the root of a binary tree.
//  At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
//  If a node has only one child, that child is guaranteed to be the left child.
//  Given the output traversal of this traversal, recover the tree and return its root.
//   
//  Example 1:
//  
//  
//  Input: traversal = "1-2--3--4-5--6--7"
//  Output: [1,2,5,3,4,6,7]
//  
//  Example 2:
//  
//  
//  Input: traversal = "1-2--3---4-5--6---7"
//  Output: [1,2,5,3,null,6,null,4,null,7]
//  
//  Example 3:
//  
//  
//  Input: traversal = "1-401--349---90--88"
//  Output: [1,401,null,349,88,90]
//  
//   
//  Constraints:
//  
//  The number of nodes in the original tree is in the range [1, 1000].
//  1 <= Node.val <= 109
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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode *> st;
        vector<pair<int, int>> nodes = parsePreorder(traversal);
        for (auto &[depth, val]: nodes) {
            while (st.size() > depth) {
                st.pop();
            }

            TreeNode *node = new TreeNode(val);
            if (!st.empty()) {
                if (!st.top()->left) {
                    st.top()->left = node;
                } else {
                    st.top()->right = node;
                }
            }
            st.push(node);
        }
        TreeNode *root = nullptr;
        while (!st.empty()) {
            root = st.top();
            st.pop();
        }
        return root;
    }

    vector<pair<int, int>> parsePreorder(string &traversal) {
        vector<pair<int, int>> nodes;
        int i = 0;
        int n = traversal.size();
        while (i < n) {
            int depth = 0;
            while (i < n && traversal[i] == '-') {
                depth += 1;
                i += 1;
            }

            int val = 0;
            while (i < n && traversal[i] != '-') {
                val = val * 10 + traversal[i] - '0';
                i += 1;
            }
            nodes.emplace_back(depth, val);
        }

        return nodes;
    }

};