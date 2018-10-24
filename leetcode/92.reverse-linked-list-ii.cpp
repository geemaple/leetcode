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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if (m >= n)
        {
            return head;
        }

        ListNode newHead(0);
        newHead.next = head;
        ListNode *cur = &newHead;

        for (auto i = 0; i < m - 1; ++i)
        {
            cur = cur->next;
        }

        head = cur;
        cur = cur->next;

        for (auto i = 0; i < n - m; ++i)
        {
            ListNode *tmp = cur->next;
            cur->next = cur->next->next;

            tmp->next = head->next;
            head->next = tmp;
        }

        return newHead.next;
    }
};
