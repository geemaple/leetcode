/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode head(0);
        ListNode *cur = &head;
        
        ListNode *left = l1;
        ListNode *right = l2;
        
        while (left || right)
        {
            int left_val = left ? left->val : INT_MAX;
            int right_val = right ? right->val : INT_MAX;
            
            if (left_val < right_val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;
            }
            
            cur = cur->next;
        }
        
        return head.next;
    }
};