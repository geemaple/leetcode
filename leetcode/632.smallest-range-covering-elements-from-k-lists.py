#  Tag: Array, Hash Table, Greedy, Sliding Window, Sorting, Heap (Priority Queue)
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
#  We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
#   
#  Example 1:
#  
#  Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
#  Output: [20,24]
#  Explanation: 
#  List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
#  List 2: [0, 9, 12, 20], 20 is in range [20,24].
#  List 3: [5, 18, 22, 30], 22 is in range [20,24].
#  
#  Example 2:
#  
#  Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
#  Output: [1,1]
#  
#   
#  Constraints:
#  
#  nums.length == k
#  1 <= k <= 3500
#  1 <= nums[i].length <= 50
#  -105 <= nums[i][j] <= 105
#  nums[i] is sorted in non-decreasing order.
#  
#  

import heapq
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        n = len(nums)
        heap = [(nums[i][0], 0, i) for i in range(n)]
        heapq.heapify(heap)
        big = max(heap)[0]

        res = None
        while len(heap) == n:
            small, index, arr_index = heapq.heappop(heap)
            if res is None or res[1] - res[0] > big - small:
                res = [small, big]

            next_index = index + 1
            if next_index < len(nums[arr_index]):
                big = max(big, nums[arr_index][next_index])
                heapq.heappush(heap, (nums[arr_index][next_index], next_index, arr_index))

        return res
    
from collections import defaultdict
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        n = len(nums)
        merge = []
        for i in range(n):
            for x in nums[i]:
                merge.append((x, i))

        merge.sort()

        l, r = -1, -1
        counter = defaultdict(int)
        count = 0
        i = 0

        for j in range(len(merge)):
            num, k = merge[j]
            counter[k] += 1
            if counter[k] == 1:
                count += 1

            while count == n:
                if l == -1 or r - l > merge[j][0] - merge[i][0]:
                    l, r = [merge[i][0], merge[j][0]]

                k = merge[i][1]
                counter[k] -= 1
                if counter[k] == 0:
                    count -= 1

                i += 1
        
        return [l, r]