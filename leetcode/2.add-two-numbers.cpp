/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (33.44%)
 * Total Accepted:    1.4M
 * Total Submissions: 4.2M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order and each of their nodes
 * contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 * 
 * Example:
 * 
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
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
