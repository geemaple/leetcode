//  Tag: String, Tree, Depth-First Search, Breadth-First Search, Design, Binary Search Tree, Binary Tree
//  Time: O(N)
//  Space: O(H)
//  Ref: -
//  Note: -

//  Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//  Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.
//  The encoded string should be as compact as possible.
//   
//  Example 1:
//  Input: root = [2,1,3]
//  Output: [2,1,3]
//  Example 2:
//  Input: root = []
//  Output: []
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [0, 104].
//  0 <= Node.val <= 104
//  The input tree is guaranteed to be a binary search tree.
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        preorder(root, res);
        return res;
    }

    void preorder(TreeNode *node, string &res) {
        if (node == nullptr) {
            return;
        }

        res += to_string(node->val) + ',';
        preorder(node->left, res);
        preorder(node->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        istringstream iss(data);
        vector<int> nodes;
        string val;
        while (getline(iss, val, ',')) {
            nodes.push_back(stoi(val));
        }

        int index = 0;
        return construct(nodes, index, INT_MIN, INT_MAX);
    }

    TreeNode* construct(vector<int> &nodes, int &index, int min_val, int max_val) {
        if (index == nodes.size() || nodes[index] < min_val || nodes[index] > max_val) {
            return nullptr;
        }

        int val = nodes[index++];
        TreeNode *root = new TreeNode(val);

        root->left = construct(nodes, index, min_val, val);
        root->right = construct(nodes, index, val, max_val);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;