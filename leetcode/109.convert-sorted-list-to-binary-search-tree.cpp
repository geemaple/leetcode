//  Tag: Linked List, Divide and Conquer, Tree, Binary Search Tree, Binary Tree
//  Time: O(NlogN)
//  Space: O(logN)
//  Ref: -
//  Note: -

//  Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height-balanced binary search tree.
//   
//  Example 1:
//  
//  
//  Input: head = [-10,-3,0,5,9]
//  Output: [0,-3,9,-10,null,5]
//  Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
//  
//  Example 2:
//  
//  Input: head = []
//  Output: []
//  
//   
//  Constraints:
//  
//  The number of nodes in head is in the range [0, 2 * 104].
//  -105 <= Node.val <= 105
//  
//  

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = nullptr;

        while (fast->next && fast->next->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        TreeNode *root = new TreeNode(slow->val);
        if (pre) {
            pre->next = nullptr;
            root->left = sortedListToBST(head);
        }

        root->right = sortedListToBST(slow->next);
        return root;
    }
};