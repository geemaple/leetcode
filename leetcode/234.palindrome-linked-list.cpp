//  Tag: Linked List, Two Pointers, Stack, Recursion
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
//   
//  Example 1:
//  
//  
//  Input: head = [1,2,2,1]
//  Output: true
//  
//  Example 2:
//  
//  
//  Input: head = [1,2]
//  Output: false
//  
//   
//  Constraints:
//  
//  The number of nodes in the list is in the range [1, 105].
//  0 <= Node.val <= 9
//  
//   
//  Follow up: Could you do it in O(n) time and O(1) space?

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
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = reverseList(slow->next);
        ListNode *left = head;
        ListNode *right = slow->next;
        while (left && right) {
            if (left->val != right->val) {
                return false;
            }

            left = left->next;
            right = right->next;
        }

        return true;
    }

    ListNode * reverseList(ListNode *node) {
        ListNode *pre = nullptr;
        ListNode *cur = node;
        while(cur) {    
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

};