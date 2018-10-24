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
    ListNode* reverseList(ListNode* head) {
        ListNode newHead(0);
        ListNode *cur = head;
        
        while (cur)
        {
            ListNode *tmp = cur;
            cur = cur->next;
            
            tmp->next = newHead.next;
            newHead.next = tmp;
        }
        
        return newHead.next;
    }
};