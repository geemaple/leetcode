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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* quick = head;
        ListNode* slow = head;
        int count = 0;
        while (quick && quick->next) {
            count += 1;
            quick = quick->next;
            
            if (count > n)
            {
                slow = slow->next;
            }            
        }
        
        slow->next = slow->next->next;
        return head;
    }
};
