#  Tag: Array, Queue, Sliding Window, Heap (Priority Queue), Monotonic Queue
#  Time: O(N)
#  Space: O(K)
#  Ref: -
#  Note: -

#  You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
#  Return the max sliding window.
#   
#  Example 1:
#  
#  Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
#  Output: [3,3,5,5,6,7]
#  Explanation: 
#  Window position                Max
#  ---------------               -----
#  [1  3  -1] -3  5  3  6  7       3
#   1 [3  -1  -3] 5  3  6  7       3
#   1  3 [-1  -3  5] 3  6  7       5
#   1  3  -1 [-3  5  3] 6  7       5
#   1  3  -1  -3 [5  3  6] 7       6
#   1  3  -1  -3  5 [3  6  7]      7
#  
#  Example 2:
#  
#  Input: nums = [1], k = 1
#  Output: [1]
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  -104 <= nums[i] <= 104
#  1 <= k <= nums.length
#  
#  

from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        q = deque()
        res = []

        for i in range(n):
            if len(q) > 0 and i - q[0] == k:
                q.popleft()

            while len(q) > 0 and nums[i] > nums[q[-1]]:
                q.pop()

            q.append(i)

            if i + 1 >= k:
                res.append(nums[q[0]])

        return res
    
import heapq
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        heap = []
        res = []

        for i in range(n):
            while len(heap) > 0 and i - heap[0][1] >= k:
                heapq.heappop(heap)

            heapq.heappush(heap, (-nums[i], i))

            if i + 1 >= k:
                res.append(-heap[0][0])

        return res