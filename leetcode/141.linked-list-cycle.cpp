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
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};
