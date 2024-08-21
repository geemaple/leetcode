#  Tag: Hash Table, Linked List, Design, Doubly-Linked List
#  Time: O(1)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
#  Implement the LRUCache class:
#  
#  LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
#  int get(int key) Return the value of the key if the key exists, otherwise return -1.
#  void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
#  
#  The functions get and put must each run in O(1) average time complexity.
#   
#  Example 1:
#  
#  Input
#  ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
#  [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
#  Output
#  [null, null, null, 1, null, -1, null, -1, 3, 4]
#  
#  Explanation
#  LRUCache lRUCache = new LRUCache(2);
#  lRUCache.put(1, 1); // cache is {1=1}
#  lRUCache.put(2, 2); // cache is {1=1, 2=2}
#  lRUCache.get(1);    // return 1
#  lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
#  lRUCache.get(2);    // returns -1 (not found)
#  lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
#  lRUCache.get(1);    // return -1 (not found)
#  lRUCache.get(3);    // return 3
#  lRUCache.get(4);    // return 4
#  
#   
#  Constraints:
#  
#  1 <= capacity <= 3000
#  0 <= key <= 104
#  0 <= value <= 105
#  At most 2 * 105 calls will be made to get and put.
#  
#  

class CacheNode:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.pre = None
        self.next = None

class DoubleLinkedList:
    def __init__(self):
        self.head = CacheNode(key=None, val=None)
        self.tail = CacheNode(key=None, val=None)
        self.head.next = self.tail
        self.tail.pre = self.head

    def move_to_front(self, node):
        if self.head.next == node:
            return

        self.remove(node)
        self.insert_front(node)

    def remove(self, node):
        node.pre.next = node.next
        node.next.pre = node.pre

    def insert_front(self, node):
        node.next = self.head.next
        node.next.pre = node
        self.head.next = node
        node.pre = self.head
    
    def pop_last(self) -> CacheNode:
        node = self.tail.pre
        if node != self.head:
            self.remove(node)
            return node


class LRUCache:
    def __init__(self, capacity: int):
        self.hash = {}
        self.cache = DoubleLinkedList()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.hash:
            node = self.hash[key]
            self.cache.move_to_front(node)
            return node.val

        return -1    

    def put(self, key: int, value: int) -> None:
        if key in self.hash:
            node = self.hash[key]
            node.val = value
            self.cache.move_to_front(node)
        else:
            node = CacheNode(key, value)
            self.hash[key] = node
            self.cache.insert_front(node)

            if len(self.hash) > self.capacity:
                node = self.cache.pop_last()
                del self.hash[node.key]

from collections import OrderedDict
class LRUCache:

    def __init__(self, capacity: int):
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key: int) -> int:
        if key in self.cache:
            val = self.cache[key]
            self.cache.move_to_end(key, last=False)
            return val

        return -1    

    def put(self, key: int, value: int) -> None:
        self.cache[key] = value
        self.cache.move_to_end(key)
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=True)

# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)