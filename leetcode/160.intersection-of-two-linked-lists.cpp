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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *curA = headA;
        ListNode *curB = headB;
        
        while (curA && curB)
        {
            if (curA == curB)
            {
                return curA;
            }
            
            curA = curA->next;
            curB = curB->next;
            
            if (curA == NULL && curB == NULL)
            {
                return NULL;
            }
            
            if (curA == NULL)
            {
                curA = headB;
            }
            
            if (curB == NULL)
            {
                curB = headA;
            }
        }
        
        return NULL;
    }
};