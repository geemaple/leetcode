#  Tag: Array, Hash Table, Sliding Window, Heap (Priority Queue)
#  Time: O(NlogK)
#  Space: O(K)
#  Ref: -
#  Note: -

#  The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.
#  
#  For examples, if arr = [2,3,4], the median is 3.
#  For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
#  
#  You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
#  Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.
#   
#  Example 1:
#  
#  Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
#  Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
#  Explanation: 
#  Window position                Median
#  ---------------                -----
#  [1  3  -1] -3  5  3  6  7        1
#   1 [3  -1  -3] 5  3  6  7       -1
#   1  3 [-1  -3  5] 3  6  7       -1
#   1  3  -1 [-3  5  3] 6  7        3
#   1  3  -1  -3 [5  3  6] 7        5
#   1  3  -1  -3  5 [3  6  7]       6
#  
#  Example 2:
#  
#  Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
#  Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
#  
#   
#  Constraints:
#  
#  1 <= k <= nums.length <= 105
#  -231 <= nums[i] <= 231 - 1
#  
#  

from collections import defaultdict
class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        n = len(nums)
        max_heap = []
        min_heap = []

        for i in range(k):
            heapq.heappush(max_heap, -nums[i])
        
        for _ in range(k >> 1): 
            heapq.heappush(min_heap, -heapq.heappop(max_heap))

        ans = [self.get_med(max_heap, min_heap, k)]
        
        table = defaultdict(int)

        for i in range(k, n):
            out_num = nums[i - k]
            in_num = nums[i]
            balance = -1 if out_num <= -max_heap[0] else 1
            table[out_num] += 1

            if in_num <= -max_heap[0]:
                balance += 1
                heapq.heappush(max_heap, -in_num)
            else:
                balance -= 1
                heapq.heappush(min_heap, in_num)

            if balance < 0:
                heapq.heappush(max_heap, -heapq.heappop(min_heap))

            if balance > 0:
                heapq.heappush(min_heap, -heapq.heappop(max_heap))

            while (table[-max_heap[0]] > 0):
                table[-max_heap[0]] -= 1
                heapq.heappop(max_heap)

            while (len(min_heap) > 0 and table[min_heap[0]] > 0):
                table[min_heap[0]] -= 1
                heapq.heappop(min_heap)

            ans.append(self.get_med(max_heap, min_heap, k))
        
        return ans
    
    def get_med(self, max_heap, min_heap, k):
        return -max_heap[0] * 1.0 if k & 1 else (min_heap[0] - max_heap[0]) / 2.0

# import heapq
# class Solution:
#     def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
#         n = len(nums)
#         max_heap = []
#         min_heap = []

#         for i in range(k):
#             heapq.heappush(max_heap, (-nums[i], i))
        
#         for _ in range(k >> 1): 
#             x, i = heapq.heappop(max_heap)
#             heapq.heappush(min_heap, (-x, i))

#         ans = [self.get_med(max_heap, min_heap, k)]

#         for i in range(k, n):
#             x = nums[i]
#             if x <= -max_heap[0][0]:
#                 heapq.heappush(max_heap, (-x, i))
#                 if nums[i - k] >= -max_heap[0][0]:
#                     self.move(max_heap, min_heap)
#             else:
#                 heapq.heappush(min_heap, (x, i))
#                 if nums[i - k] <= -max_heap[0][0]:
#                     self.move(min_heap, max_heap)

#             while max_heap and max_heap[0][1] <= i - k: 
#                 heapq.heappop(max_heap)
#             while min_heap and min_heap[0][1] <= i - k: 
#                 heapq.heappop(min_heap)

#             ans.append(self.get_med(max_heap, min_heap, k))
        
#         return ans

#     def move(self, h1, h2):
#         x, i = heapq.heappop(h1)
#         heapq.heappush(h2, (-x, i))
    
#     def get_med(self, max_heap, min_heap, k):
#         return -max_heap[0][0] * 1.0 if k & 1 else (min_heap[0][0] - max_heap[0][0]) / 2.0

