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
    
private:
    string postOrderTraverse(vector<TreeNode *> &res, unordered_map<string, int> &map, TreeNode* node){
        
        if (node == NULL){
            return "#";
        }
        
        string s = to_string(node->val) + "(" + postOrderTraverse(res, map, node->left) + "," + postOrderTraverse(res, map, node->right) + ")" ;
        if (map[s] == 1){
            res.push_back(node);
        }
        
        map[s] += 1;
        
        return s;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> res;
        unordered_map<string, int> map;
        
        postOrderTraverse(res, map, root);
        
        return res;
    }
};