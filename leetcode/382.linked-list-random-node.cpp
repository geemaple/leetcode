//  Tag: Linked List, Math, Reservoir Sampling, Randomized
//  Time: O(N)
//  Space: O(1)
//  Ref: -
//  Note: -

//  Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
//  Implement the Solution class:
//  
//  Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
//  int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.
//  
//   
//  Example 1:
//  
//  
//  Input
//  ["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
//  [[[1, 2, 3]], [], [], [], [], []]
//  Output
//  [null, 1, 3, 2, 2, 3]
//  
//  Explanation
//  Solution solution = new Solution([1, 2, 3]);
//  solution.getRandom(); // return 1
//  solution.getRandom(); // return 3
//  solution.getRandom(); // return 2
//  solution.getRandom(); // return 2
//  solution.getRandom(); // return 3
//  // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
//  
//   
//  Constraints:
//  
//  The number of nodes in the linked list will be in the range [1, 104].
//  -104 <= Node.val <= 104
//  At most 104 calls will be made to getRandom.
//  
//   
//  Follow up:
//  
//  What if the linked list is extremely large and its length is unknown to you?
//  Could you solve this efficiently without using extra space?
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
    ListNode *h;
    Solution(ListNode* head) {
        h = head;
    }
    
    int getRandom() {
        ListNode *res = h;
        ListNode *cur = h->next;
        int i = 2;
        while (cur) {
            if (rand() % i == 0) {
                res = cur;
            }
            cur = cur->next;
            i++;
        }
        return res->val; 

    }
};

class Solution {
public:
    ListNode* h;
    int count;
    Solution(ListNode* head) {
        h = head;
        ListNode* cur = h;
        count = 0;
        while (cur) {
            cur = cur->next;
            count++;
        }
    }
    
    int getRandom() {
        int t = rand() % count + 1;
        ListNode* cur = h;
        for (int i = 1; i < t; i++) {
            cur = cur->next;
        }
        return cur->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */