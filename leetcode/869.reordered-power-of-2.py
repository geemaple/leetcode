#  Tag: Hash Table, Math, Sorting, Counting, Enumeration
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/7jkS-3NNIKU

#  You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
#  Return true if and only if we can do this so that the resulting number is a power of two.
#   
#  Example 1:
#  
#  Input: n = 1
#  Output: true
#  
#  Example 2:
#  
#  Input: n = 10
#  Output: false
#  
#   
#  Constraints:
#  
#  1 <= n <= 109
#  
#  

class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        table = []
        for i in range(32):
            num_str = str(2 ** i)
            table.append(sorted(num_str))

        return sorted(str(n)) in table
    
class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        count = self.counter(n)
        for i in range(32):
            if count == self.counter(2 ** i):
                return True

        return False

    def counter(self, n) -> int:
        res = 0
        while n > 0:
            res += 10 ** (n % 10)
            n //= 10

        return res