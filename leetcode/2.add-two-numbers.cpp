//  Tag: Linked List, Math, Recursion
//  Time: O(N + M)
//  Space: O(1)
//  Ref: -
//  Note: -

//  You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
//  You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//   
//  Example 1:
//  
//  
//  Input: l1 = [2,4,3], l2 = [5,6,4]
//  Output: [7,0,8]
//  Explanation: 342 + 465 = 807.
//  
//  Example 2:
//  
//  Input: l1 = [0], l2 = [0]
//  Output: [0]
//  
//  Example 3:
//  
//  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//  Output: [8,9,9,9,0,0,0,1]
//  
//   
//  Constraints:
//  
//  The number of nodes in each linked list is in the range [1, 100].
//  0 <= Node.val <= 9
//  It is guaranteed that the list represents a number that does not have leading zeros.
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;
        ListNode dummy = ListNode(0);
        ListNode *cur = &dummy;
        int extra = 0;
        while (cur1 || cur2 || extra) {
            int v1 = cur1 ? cur1->val: 0;
            int v2 = cur2 ? cur2->val: 0;
            int val = v1 + v2 + extra;
            extra = val / 10;
            cur->next = new ListNode(val % 10);
            cur = cur->next;
            cur1 = cur1 ? cur1->next: nullptr;
            cur2 = cur2 ? cur2->next: nullptr;
        }
        return dummy.next;
    }
};