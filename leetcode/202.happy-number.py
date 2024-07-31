#  Tag: Hash Table, Math, Two Pointers
#  Time: O(S)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Write an algorithm to determine if a number n is happy.
#  A happy number is a number defined by the following process:
#  
#  Starting with any positive integer, replace the number by the sum of the squares of its digits.
#  Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
#  Those numbers for which this process ends in 1 are happy.
#  
#  Return true if n is a happy number, and false if not.
#   
#  Example 1:
#  
#  Input: n = 19
#  Output: true
#  Explanation:
#  12 + 92 = 82
#  82 + 22 = 68
#  62 + 82 = 100
#  12 + 02 + 02 = 1
#  
#  Example 2:
#  
#  Input: n = 2
#  Output: false
#  
#   
#  Constraints:
#  
#  1 <= n <= 231 - 1
#  
#  

class Solution:
    def isHappy(self, n: int) -> bool:
        cache = set()

        while n not in cache:
            cache.add(n)
            tmp = 0
            while n > 0:
                tmp += (n % 10) ** 2
                n = n // 10

            if tmp == 1:
                return True
            else:
                n = tmp

        return False                
    
class Solution:
    def isHappy(self, n: int) -> bool:
        slow = n
        fast = n
        while True:
            slow = self.next_node(slow)
            fast = self.next_node(fast)
            fast = self.next_node(fast)

            if slow == fast:
                break

        return slow == 1                
    
    def next_node(self, n) -> int:
        res = 0
        while n > 0:
            res += (n % 10) ** 2
            n = n // 10
        return res