#  Tag: Array, Hash Table, Union Find
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
#  You must write an algorithm that runs in O(n) time.
#   
#  Example 1:
#  
#  Input: nums = [100,4,200,1,3,2]
#  Output: 4
#  Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
#  
#  Example 2:
#  
#  Input: nums = [0,3,7,2,5,8,4,6,0,1]
#  Output: 9
#  
#   
#  Constraints:
#  
#  0 <= nums.length <= 105
#  -109 <= nums[i] <= 109
#  
#  

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        cache = set(nums)
        res = 0
        while len(cache) > 0:
            x = next(iter(cache))
            cache.remove(x)
            count = 1

            b = x + 1
            while b in cache:
                cache.remove(b)
                b += 1
                count += 1

            s = x - 1
            while s in cache:
                cache.remove(s)
                s -= 1
                count += 1

            res = max(res, count)

        return res
        

class UnionFind:
    def __init__(self, n):
        self.table = [i for i in range(n)]
        self.count = [1 for i in range(n)]

    def connect(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)

        if root_a != root_b:
            self.table[root_a] = root_b
            self.count[root_b] += self.count[root_a]

    def find(self, x):
        if self.table[x] == x:
            return x

        self.table[x] = self.find(self.table[x])
        return self.table[x]

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        n = len(nums)
        idx = {}
        for i in range(n):
            idx[nums[i]] = i

        uf = UnionFind(n)
        for x in idx:
            if x + 1 in idx:
                uf.connect(idx[x], idx[x + 1])

        res = 0
        for x in uf.count:
            res = max(res, x)

        return res