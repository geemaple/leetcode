//  Tag: Linked List, Two Pointers, Divide and Conquer, Sorting, Merge Sort
//  Time: O(NlogN)
//  Space: O(logN)
//  Ref: -
//  Note: -

//  Given the head of a linked list, return the list after sorting it in ascending order.
//   
//  Example 1:
//  
//  
//  Input: head = [4,2,1,3]
//  Output: [1,2,3,4]
//  
//  Example 2:
//  
//  
//  Input: head = [-1,5,3,4,0]
//  Output: [-1,0,3,4,5]
//  
//  Example 3:
//  
//  Input: head = []
//  Output: []
//  
//   
//  Constraints:
//  
//  The number of nodes in the list is in the range [0, 5 * 104].
//  -105 <= Node.val <= 105
//  
//   
//  Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = nullptr;

        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        pre->next = nullptr;
        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);

        ListNode dummy = ListNode();
        ListNode *cur = &dummy;
        while (left && right) {
            if (left->val <= right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }
        cur->next = left ? left : right;
        return dummy.next;
    }
};