//  Tag: Linked List, Divide and Conquer, Heap (Priority Queue), Merge Sort
//  Time: O(NlogK)
//  Space: O(K)
//  Ref: -
//  Note: -

//  You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
//  Merge all the linked-lists into one sorted linked-list and return it.
//   
//  Example 1:
//  
//  Input: lists = [[1,4,5],[1,3,4],[2,6]]
//  Output: [1,1,2,3,4,4,5,6]
//  Explanation: The linked-lists are:
//  [
//    1->4->5,
//    1->3->4,
//    2->6
//  ]
//  merging them into one sorted list:
//  1->1->2->3->4->4->5->6
//  
//  Example 2:
//  
//  Input: lists = []
//  Output: []
//  
//  Example 3:
//  
//  Input: lists = [[]]
//  Output: []
//  
//   
//  Constraints:
//  
//  k == lists.length
//  0 <= k <= 104
//  0 <= lists[i].length <= 500
//  -104 <= lists[i][j] <= 104
//  lists[i] is sorted in ascending order.
//  The sum of lists[i].length will not exceed 104.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        queue<ListNode *> q(lists.begin(), lists.end());
        while (q.size() > 1) {
            ListNode *one = q.front();
            q.pop();
            ListNode *other = q.front();
            q.pop();
            q.push(merge2(one, other));
        }

        return q.empty() ? nullptr : q.front();
    }

    ListNode* merge2(ListNode *one, ListNode *other) {
        ListNode head = ListNode();
        ListNode *cur = &head;
        while (one && other) {
            if (one->val <= other->val) {
                cur->next = one;
                one = one->next;
            } else {
                cur->next = other;
                other = other->next;
            }
            cur = cur->next;
        }

        cur->next = one ? one : other;
        return head.next;
    }
};


struct cmp {
    bool operator()(const ListNode* a, const ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        
        for(auto i = 0; i < lists.size(); ++i)
        {
            if (lists[i])
            {
                heap.push(lists[i]);
            }
        }
        
        ListNode head = ListNode();
        ListNode *cur = &head;
        while(!heap.empty())
        {
            ListNode *neighbor = heap.top();
            heap.pop();
            cur->next = neighbor;
            cur = cur->next;
            
            if (neighbor->next)
            {
                heap.push(neighbor->next);
            }
        }
        
        return head.next;
    }
};