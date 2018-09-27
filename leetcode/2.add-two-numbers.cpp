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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int addOn = 0;
        ListNode *cur1 = l1;
        ListNode *cur2 = l2;

        ListNode *root = new ListNode(0);
        ListNode *cur = root;

        while (cur1 || cur2 || addOn)
        {
            int digit1 = cur1 ? cur1->val: 0;
            int digit2 = cur2 ? cur2->val: 0;
            int number = digit1 + digit2 + addOn;
            addOn = number / 10;
            cur->next = new ListNode(number % 10);

            if (cur1)
            {
                cur1 = cur1->next;
            }
            
            if (cur2)
            {
                cur2 = cur2->next;
            }
            
            cur = cur->next;
        }

        return root->next;
    }
};
