#  Tag: Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect
#  Time: O(N), O(C*logK)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
#   
#  Example 1:
#  Input: nums = [1,1,1,2,2,3], k = 2
#  Output: [1,2]
#  Example 2:
#  Input: nums = [1], k = 1
#  Output: [1]
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  -104 <= nums[i] <= 104
#  k is in the range [1, the number of unique elements in the array].
#  It is guaranteed that the answer is unique.
#  
#   
#  Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
#  

import heapq
import collections
class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
    
        counter = collections.Counter(nums)
        res = []

        for num, frequency in counter.items():
            heapq.heappush(res, (frequency, num))            
            if len(res) > k:
                heapq.heappop(res)

        return [x[1] for x in res]

class Solution:
    def topKFrequent(self, nums: list[int], k: int) -> list[int]:
    
        counter = {}
        max_count = 0
        for n in nums:
            counter[n] = counter.get(n, 0) + 1
            if counter[n] > max_count:
                max_count = counter[n]

        buckets = [[] for i in range(max_count + 1)]
        for num, frequency in counter.items():
            buckets[frequency].append(num)

        res = []
        for i in range(max_count, 0, -1):
            if len(res) == k:
                break

            for n in buckets[i]:
                if len(res) < k:
                    res.append(n)

        return res