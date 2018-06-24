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
    static bool greater(ListNode *left, ListNode *right){
        return left->val > right -> val;
    }
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode *> list;
        ListNode head(0);
        ListNode *cur = &head;
        
        for(auto i = 0; i < lists.size(); ++i){
            ListNode *node = lists[i];
            if (node != NULL){
                list.push_back(node);
            }
        }
        
        make_heap(list.begin(), list.end(), greater);
        
        while(!list.empty()){
            
            ListNode *node = list.front();
            pop_heap(list.begin(), list.end(), greater);
            list.pop_back();
            
            cur->next = node;
            if (node->next){
                list.push_back(node->next);
                push_heap(list.begin(), list.end(), greater);
            }
            
            cur = cur->next;
        }
        
        return head.next;
    }
};