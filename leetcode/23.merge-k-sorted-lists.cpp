/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

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
        
        ListNode head(0);
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