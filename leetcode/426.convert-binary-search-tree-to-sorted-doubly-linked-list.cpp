/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
private:    
    Node head;
    Node *pre = &head;
    void helper(Node *cur)
    {
        if (cur == NULL)
        {
            return;
        }
        
        helper(cur->left);
        // root
        pre->right = cur;
        cur->left = pre;
        pre = pre->right;
        
        head.right->left = cur;
        
        helper(cur->right);
    }
public:
    Node* treeToDoublyList(Node* root) {
        
        if (root == NULL)
        {
            return NULL;
        }
        
        helper(root);
        head.right->left->right = head.right;
        
        return head.right;
    }
};