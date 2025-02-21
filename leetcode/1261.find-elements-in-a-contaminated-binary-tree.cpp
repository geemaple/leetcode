//  Tag: Hash Table, Tree, Depth-First Search, Breadth-First Search, Design, Binary Tree
//  Time: O(N)
//  Space: O(N)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/1Npf6eFaYRQ

//  Given a binary tree with the following rules:
//  
//  root.val == 0
//  For any treeNode:
//  	
//  If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
//  If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
//  
//  
//  
//  Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
//  Implement the FindElements class:
//  
//  FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
//  bool find(int target) Returns true if the target value exists in the recovered binary tree.
//  
//   
//  Example 1:
//  
//  
//  Input
//  ["FindElements","find","find"]
//  [[[-1,null,-1]],[1],[2]]
//  Output
//  [null,false,true]
//  Explanation
//  FindElements findElements = new FindElements([-1,null,-1]); 
//  findElements.find(1); // return False 
//  findElements.find(2); // return True 
//  Example 2:
//  
//  
//  Input
//  ["FindElements","find","find","find"]
//  [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
//  Output
//  [null,true,true,false]
//  Explanation
//  FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
//  findElements.find(1); // return True
//  findElements.find(3); // return True
//  findElements.find(5); // return False
//  Example 3:
//  
//  
//  Input
//  ["FindElements","find","find","find","find"]
//  [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
//  Output
//  [null,true,false,false,true]
//  Explanation
//  FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
//  findElements.find(2); // return True
//  findElements.find(3); // return False
//  findElements.find(4); // return False
//  findElements.find(5); // return True
//  
//   
//  Constraints:
//  
//  TreeNode.val == -1
//  The height of the binary tree is less than or equal to 20
//  The total number of nodes is between [1, 104]
//  Total calls of find() is between [1, 104]
//  0 <= target <= 106
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
class FindElements {
public:
    unordered_set<int> visited;
    FindElements(TreeNode* root) {
        root->val = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            visited.insert(cur->val);
            if (cur->left) {
                cur->left->val = cur->val * 2 + 1;
                q.push(cur->left);
            }

            if (cur->right) {
                cur->right->val = cur->val * 2 + 2;
                q.push(cur->right);
            }
        }
    }
    
    bool find(int target) {
        return visited.count(target) > 0;
    }
};

class FindElements {
public:
    TreeNode* root;
    FindElements(TreeNode* root) : root(root) {}

    bool find(int target) {
        int path = target + 1;
        TreeNode* node = root;
        int shift = 31;
        while (!(path & (1 << shift))) { // Skip leading zeros
            shift -= 1; 
            continue;
        }
        shift -= 1;  // Skip leading one

        while (shift >= 0) {
            if (!node) return false;
            node = (path & (1 << shift)) ? node->right : node->left;
            shift -= 1;
        }

        return node != nullptr;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */