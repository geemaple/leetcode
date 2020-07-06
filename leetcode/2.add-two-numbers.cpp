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
        
        int extra = 0;
        ListNode *root = new ListNode(0);
        ListNode *pre = root;

        while (l1 || l2 || extra)
        {
            int digit1 = l1 ? l1->val: 0;
            int digit2 = l2 ? l2->val: 0;
            int number = digit1 + digit2 + extra;
            
            extra = number / 10;
            pre->next = new ListNode(number % 10);

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            pre = pre->next;
        }

        return root->next;
    }
};
