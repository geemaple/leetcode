//  Tag: Linked List, Recursion
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
//  k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
//  You may not alter the values in the list's nodes, only nodes themselves may be changed.
//   
//  Example 1:
//  
//  
//  Input: head = [1,2,3,4,5], k = 2
//  Output: [2,1,4,3,5]
//  
//  Example 2:
//  
//  
//  Input: head = [1,2,3,4,5], k = 3
//  Output: [3,2,1,4,5]
//  
//   
//  Constraints:
//  
//  The number of nodes in the list is n.
//  1 <= k <= n <= 5000
//  0 <= Node.val <= 1000
//  
//   
//  Follow-up: Can you solve the problem in O(1) extra memory space?
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }

        ListNode dummy = ListNode(0, head);
        ListNode *cur = &dummy;
        while (cur) {
            ListNode *tail = cur;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) {
                    return dummy.next;
                }
            }

            ListNode *group_head = cur;
            ListNode *group_tail = cur->next;
            ListNode *pre = tail->next;
            cur = cur->next;

            for (int i = 0; i < k; i++) {
                ListNode *tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }

            group_head->next = pre;
            cur = group_tail;
        }

        return dummy.next;
    }
};