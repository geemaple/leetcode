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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k < 2)
        {
            return head;
        }
        
        ListNode newHead = ListNode(0);
    
        int count = 0;
        
        ListNode *segHead = &newHead;
        ListNode *cur = head;
        
        // reverse very k nodes
        while (cur)
        {
            ListNode *tmp = cur;
            cur = cur->next;
            
            tmp->next = segHead->next;
            segHead->next = tmp;
            count ++;
                
            if (count % k == 0)
            {
                while(segHead->next)
                {
                    segHead = segHead->next;
                }
            }
        }
        
        // reverse back last < k
        if (count % k != 0)
        {
            cur = segHead->next;
            segHead->next = NULL;
            while (cur)
            {
                ListNode *tmp = cur;
                cur = cur->next;

                tmp->next = segHead->next;
                segHead->next = tmp;
            }
        }
        
        return newHead.next;
    }
};