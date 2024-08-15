#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.

 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        helper(root, nullptr);
        return res;
    }

    void helper(TreeNode* node, TreeNode*pre) {
        if (!node) {
            return;
        }

        helper(node->left, pre);
        cout << node->val << ", " << (pre ? pre->val : -1) << endl;
        if (pre) {
            res = min(res, abs(pre->val - node->val));
        }
        pre = node;
        
        helper(node->right, pre);
    }
};

int main() {
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(7);
    
    Solution s;
    cout << "Longest Palindromic Substring: " << s.getMinimumDifference(root) << endl;
    return 0;
}
