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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        bool hasCycle = false;
        
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                hasCycle = true;
                break;
            }
        }
        
        if (hasCycle)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }

            return slow; 
        }

        return NULL;
    }
};