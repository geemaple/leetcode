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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode newList(0);
        ListNode *new_cur = &newList;
        
        ListNode oldList(0);
        oldList.next = head;
        ListNode *cur = &oldList;
        
        while(cur && cur->next)
        {
            if (cur->next->val < x)
            {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                
                // append to new list
                tmp->next = NULL;
                new_cur->next = tmp;
                new_cur = new_cur->next;
            }
            else
            {
                cur = cur->next;
            }          
        }
        
        new_cur->next = oldList.next;
        
        return newList.next;
    }
};