#  Tag: Hash Table, Linked List, Design, Doubly-Linked List
#  Time: O(1)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.
#  Implement the AllOne class:
#  
#  AllOne() Initializes the object of the data structure.
#  inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
#  dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
#  getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
#  getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
#  
#  Note that each function must run in O(1) average time complexity.
#   
#  Example 1:
#  
#  Input
#  ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
#  [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
#  Output
#  [null, null, null, "hello", "hello", null, "hello", "leet"]
#  
#  Explanation
#  AllOne allOne = new AllOne();
#  allOne.inc("hello");
#  allOne.inc("hello");
#  allOne.getMaxKey(); // return "hello"
#  allOne.getMinKey(); // return "hello"
#  allOne.inc("leet");
#  allOne.getMaxKey(); // return "hello"
#  allOne.getMinKey(); // return "leet"
#  
#   
#  Constraints:
#  
#  1 <= key.length <= 10
#  key consists of lowercase English letters.
#  It is guaranteed that for each call to dec, key is existing in the data structure.
#  At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.
#  
#  

class ListNode:
    def __init__(self, count, key):
        self.count = count
        self.keys = set([key])
        self.pre = None
        self.next = None

class AllOne:

    def __init__(self):
        self.key_count = {}
        self.count_node = {}
        self.head = ListNode(0, None)
        self.tail = ListNode(0, None)
        self.head.next = self.tail
        self.tail.pre = self.head

    def insert_after(self, pre, cur):
        cur.next = pre.next
        cur.next.pre = cur
        cur.pre = pre
        pre.next = cur

    def remove(self, cur):
        cur.pre.next = cur.next
        cur.next.pre = cur.pre
        del self.count_node[cur.count]

    def inc(self, key: str) -> None:
        count = self.key_count.get(key, 0) + 1
        self.key_count[key] = count

        if count == 1:
            if 1 not in self.count_node:
                new_node = ListNode(1, key)
                self.count_node[1] = new_node
                self.insert_after(self.head, new_node)
            else:
                self.count_node[1].keys.add(key)
        else:
            cur = self.count_node[count - 1]
            cur.keys.remove(key)
            pre = cur

            if len(cur.keys) == 0:
                pre = cur.pre
                self.remove(cur)
            
            if count not in self.count_node:
                new_node = ListNode(count, key)
                self.count_node[count] = new_node
                self.insert_after(pre, new_node)
            else:
                self.count_node[count].keys.add(key)

    def dec(self, key: str) -> None:
        if key not in self.key_count:
            return

        count = self.key_count[key]
        if count == 1:
            del self.key_count[key]
            cur = self.count_node[1]
            cur.keys.remove(key)

            if len(cur.keys) == 0:
                self.remove(cur)
    
        else:
            self.key_count[key] = count - 1
            cur = self.count_node[count]
            cur.keys.remove(key)
            
            if len(cur.keys) == 0:
                self.remove(cur)

            if count - 1 not in self.count_node:
                node = ListNode(count - 1, key)
                self.insert_after(cur.pre, node)
                self.count_node[count - 1] = node
            else:
                self.count_node[count - 1].keys.add(key)

    def getMaxKey(self) -> str:
        return "" if self.tail.pre == self.head else next(iter(self.tail.pre.keys))

    def getMinKey(self) -> str:
        return "" if self.head.next == self.tail else next(iter(self.head.next.keys))

# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()