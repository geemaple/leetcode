//  Tag: Linked List, Math
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -
//  Video: https://youtu.be/d8qz9mvARt8

//  Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
//  Return the decimal value of the number in the linked list.
//  The most significant bit is at the head of the linked list.
//   
//  Example 1:
//  
//  
//  Input: head = [1,0,1]
//  Output: 5
//  Explanation: (101) in base 2 = (5) in base 10
//  
//  Example 2:
//  
//  Input: head = [0]
//  Output: 0
//  
//   
//  Constraints:
//  
//  The Linked List is not empty.
//  Number of nodes will not exceed 30.
//  Each node's value is either 0 or 1.
//  
//  

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *cur = head;
        int res = 0;
        while (cur) {
            res = res * 2 + cur->val;
            cur = cur->next;
        }
        return res;
    }
};