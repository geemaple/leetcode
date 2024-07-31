//  Tag: Tree, Depth-First Search, Breadth-First Search, Design, String, Binary Tree
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: Serialization

//  Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
//  Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
//  Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
//   
//  Example 1:
//  
//  
//  Input: root = [1,2,3,null,null,4,5]
//  Output: [1,2,3,null,null,4,5]
//  
//  Example 2:
//  
//  Input: root = []
//  Output: []
//  
//   
//  Constraints:
//  
//  The number of nodes in the tree is in the range [0, 104].
//  -1000 <= Node.val <= 1000
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
        vector<TreeNode *> nodes;
        vector<TreeNode *> q;
        q.push_back(root);
        int index = 0;
        while (index < q.size()) {
            TreeNode *node = q[index];
            if (node){
                q.push_back(node->left);
                q.push_back(node->right);
            }

            nodes.push_back(node);
            index += 1;
        }

        while (nodes.size() > 0 && nodes[nodes.size() - 1] == nullptr) {
            nodes.pop_back();
        }

        string res;
        for (auto *n : nodes) {
            res += (n ? to_string(n->val) : "#") + ",";
        }

        if (res.size() > 0) {
            res.pop_back();
        }

        return "[" + res + "]";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data.size() == 2) {
            return nullptr;
        }

        vector<string> nodes;
        int start = 0;
        int pos = 0;
        data = data.substr(1, data.size() - 2);
        while ((pos = data.find(",", start)) != string::npos){
            string sub = data.substr(start, pos - start);
            nodes.push_back(sub);
            start = pos + 1;
        }
        string last = data.substr(start, data.size() - start);
        nodes.push_back(last);
        
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode *> q;
        q.push(root);
        bool isLeft = true;

        for (int i = 1; i < nodes.size(); i++) {
            string val = nodes[i];
            if (val != "#") {
                TreeNode *child = new TreeNode(stoi(val));
                TreeNode *node = q.front();
                
                if (isLeft) {
                    node->left = child;
                } else {
                    node->right = child;
                }

                q.push(child);
            }

            if (!isLeft) {
                q.pop();
            }

            isLeft = !isLeft;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));