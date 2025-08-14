#  Tag: Array, Binary Search, Segment Tree, Ordered Set
#  Time: O(NLogN)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/z3WygSNkRLM

#  You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.
#  From left to right, place the fruits according to these rules:
#  
#  Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
#  Each basket can hold only one type of fruit.
#  If a fruit type cannot be placed in any basket, it remains unplaced.
#  
#  Return the number of fruit types that remain unplaced after all possible allocations are made.
#   
#  Example 1:
#  
#  Input: fruits = [4,2,5], baskets = [3,5,4]
#  Output: 1
#  Explanation:
#  
#  fruits[0] = 4 is placed in baskets[1] = 5.
#  fruits[1] = 2 is placed in baskets[0] = 3.
#  fruits[2] = 5 cannot be placed in baskets[2] = 4.
#  
#  Since one fruit type remains unplaced, we return 1.
#  
#  Example 2:
#  
#  Input: fruits = [3,6,1], baskets = [6,4,7]
#  Output: 0
#  Explanation:
#  
#  fruits[0] = 3 is placed in baskets[0] = 6.
#  fruits[1] = 6 cannot be placed in baskets[1] = 4 (insufficient capacity) but can be placed in the next available basket, baskets[2] = 7.
#  fruits[2] = 1 is placed in baskets[1] = 4.
#  
#  Since all fruits are successfully placed, we return 0.
#  
#   
#  Constraints:
#  
#  n == fruits.length == baskets.length
#  1 <= n <= 105
#  1 <= fruits[i], baskets[i] <= 109
#  
#  

class SegmentTree:
    def __init__(self, baskets: list):
        n = len(baskets)
        size = 4 * n
        self.seg = [0] * size
        self.build(baskets, 1, 0, n - 1)

    def build(self, baskets: list, v: int, i: int, j: int):
        if i == j:
            self.seg[v] = baskets[i]
            return

        m = (i + j) // 2
        self.build(baskets, 2 * v, i, m)
        self.build(baskets, 2 * v + 1, m + 1, j)
        self.seg[v] = max(self.seg[2 * v], self.seg[2 * v + 1])

    def put(self, v: int, i: int, j: int, x: int) -> int:
        if self.seg[v] < x:
            return -1

        if i == j:
            self.seg[v] = 0
            return i

        m = (i + j) // 2
        index = self.put(2 * v, i, m, x)
        if index == -1:
            index = self.put(2 * v + 1, m + 1, j, x)

        self.seg[v] = max(self.seg[2 * v], self.seg[2 * v + 1])
        return index

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(baskets)
        seg = SegmentTree(baskets)
        res = 0
        for x in fruits:
            if seg.put(1, 0, n - 1, x) == -1:
                res += 1
            
        return res
