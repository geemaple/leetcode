//  Tag: Hash Table, Linked List, Design, Doubly-Linked List
//  Time: O(1)
//  Space: O(N)
//  Ref: -
//  Note: -

//  Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.
//  Implement the AllOne class:
//  
//  AllOne() Initializes the object of the data structure.
//  inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
//  dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
//  getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
//  getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
//  
//  Note that each function must run in O(1) average time complexity.
//   
//  Example 1:
//  
//  Input
//  ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
//  [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
//  Output
//  [null, null, null, "hello", "hello", null, "hello", "leet"]
//  
//  Explanation
//  AllOne allOne = new AllOne();
//  allOne.inc("hello");
//  allOne.inc("hello");
//  allOne.getMaxKey(); // return "hello"
//  allOne.getMinKey(); // return "hello"
//  allOne.inc("leet");
//  allOne.getMaxKey(); // return "hello"
//  allOne.getMinKey(); // return "leet"
//  
//   
//  Constraints:
//  
//  1 <= key.length <= 10
//  key consists of lowercase English letters.
//  It is guaranteed that for each call to dec, key is existing in the data structure.
//  At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.
//  
//  

class AllOne {
    struct ListNode {
        int count;
        unordered_set<string> keys;
        ListNode *pre;
        ListNode *next;

        ListNode(int count, string key) : count(count), pre(nullptr), next(nullptr){
            keys.insert(key);
        }
    };
public:
    unordered_map<string, int> key_count;
    unordered_map<int, ListNode*> count_node;
    ListNode* head;
    ListNode* tail;
    
    ~AllOne() {
        ListNode *cur = head;
        while (cur) {
            ListNode *tmp = cur->next;
            delete cur;
            cur = tmp;
        };
    }
    
    AllOne() {
        head = new ListNode(0, "");
        tail = new ListNode(0, "");
        head->next = tail;
        tail->pre = head;
    }
    
    void insert_after(ListNode *pre, ListNode *cur){
        cur->next = pre->next;
        cur->next->pre = cur;
        pre->next = cur;
        cur->pre = pre;
    }
    
    void remove(ListNode *cur) {
        cur->pre->next = cur->next;
        cur->next->pre = cur->pre;
        count_node.erase(cur->count);
    }
    
    void inc(string key) {
        int count = key_count[key] + 1;
        key_count[key] = count;
        if (count == 1) {
            if (count_node.find(count) == count_node.end()) {
                ListNode *new_node = new ListNode(count, key);
                count_node[count] = new_node;
                insert_after(head, new_node);
            } else {
                count_node[count]->keys.insert(key);
            }
        } else {
            ListNode *cur = count_node[count - 1];
            ListNode *pre = cur;
            cur->keys.erase(key);

            if (cur->keys.empty()) {
                pre = cur->pre;
                remove(cur);
            }
            
            if (count_node.find(count) == count_node.end()) {
                ListNode *new_node = new ListNode(count, key);
                count_node[count] = new_node;
                insert_after(pre, new_node);
            } else {
                count_node[count]->keys.insert(key);
            }
            
        }
    }
    
    void dec(string key) {
        if (key_count.find(key) == key_count.end()) {
            return;
        }
        
        int count = key_count[key] - 1;
        if (count == 0) {
            key_count.erase(key);
            ListNode *cur = count_node[count + 1];
            cur->keys.erase(key);
            
            if (cur->keys.empty()) {
                remove(cur);
            }
        } else {
            key_count[key] = count;
            ListNode *cur = count_node[count + 1];
            ListNode *pre = cur->pre;
            cur->keys.erase(key);
            
            if (cur->keys.empty()) {
                remove(cur);
            }
            
            if (count_node.find(count) == count_node.end()) {
                ListNode *new_node = new ListNode(count, key);
                count_node[count] = new_node;
                insert_after(pre, new_node);
            } else {
                count_node[count]->keys.insert(key);
            }
        }
    }
    
    string getMaxKey() {
        return tail->pre == head ? "": *tail->pre->keys.begin();
    }
    
    string getMinKey() {
        return head->next == tail ? "": *head->next->keys.begin();
    }
};