#  Tag: Linked List, Math, Reservoir Sampling, Randomized
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
#  Implement the Solution class:
#  
#  Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
#  int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.
#  
#   
#  Example 1:
#  
#  
#  Input
#  ["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
#  [[[1, 2, 3]], [], [], [], [], []]
#  Output
#  [null, 1, 3, 2, 2, 3]
#  
#  Explanation
#  Solution solution = new Solution([1, 2, 3]);
#  solution.getRandom(); // return 1
#  solution.getRandom(); // return 3
#  solution.getRandom(); // return 2
#  solution.getRandom(); // return 2
#  solution.getRandom(); // return 3
#  // getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
#  
#   
#  Constraints:
#  
#  The number of nodes in the linked list will be in the range [1, 104].
#  -104 <= Node.val <= 104
#  At most 104 calls will be made to getRandom.
#  
#   
#  Follow up:
#  
#  What if the linked list is extremely large and its length is unknown to you?
#  Could you solve this efficiently without using extra space?
#  
#  

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

import random
class Solution:

    def __init__(self, head: Optional[ListNode]):

        self.head = head
        cur = head
        count = 0
        while cur is not None:
            cur = cur.next
            count += 1

        self.count = count

    def getRandom(self) -> int:

        t = random.randint(1, self.count)
        res = self.head
        for i in range(1, t):
            res = res.next
        
        return res.val

import random
class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.head = head


    def getRandom(self) -> int:
        res = self.head
        node = res.next
        i = 1
        while node is not None:
            if (random.randint(0, i) == 0):
                res = node

            i += 1
            node = node.next
        
        return res.val
# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()