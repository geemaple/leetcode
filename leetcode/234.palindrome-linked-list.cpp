/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    void reverseList(ListNode *head) {
        ListNode *cur = head->next;
        head->next = NULL;
        
        while (cur != NULL)
        {
            ListNode *next = cur->next;
            cur->next = head->next;
            head->next = cur;
            cur = next;
        }
    }
    
public:
    bool isPalindrome(ListNode* head) {
        
        ListNode newHead = ListNode(0);
        newHead.next = head;
        
        ListNode* slow = &newHead;
        ListNode* fast = &newHead;
        
        // find middle, AKA slow
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse later half
        reverseList(slow);
        
        ListNode *left = head;
        ListNode *right = slow->next;
        
        bool result = true;
        
        while (left != NULL && right != NULL)
        {
            if (left->val != right->val)
            {
                result = false;
                break;
            }
            
            left = left->next;
            right = right->next;
        }
        
        // reverse later half back
        // reverseList(slow);
        
        return result;
    }
};
