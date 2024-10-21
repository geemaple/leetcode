#  Tag: Array, Divide and Conquer, Quickselect, Sorting, Heap (Priority Queue)
#  Time: O(N) ～ O(N^2)
#  Space: O(1)
#  Ref: -
#  Note: QuickSelection

#  Given an integer array nums and an integer k, return the kth largest element in the array.
#  Note that it is the kth largest element in the sorted order, not the kth distinct element.
#  Can you solve it without sorting?
#   
#  Example 1:
#  Input: nums = [3,2,1,5,6,4], k = 2
#  Output: 5
#  Example 2:
#  Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
#  Output: 4
#  
#   
#  Constraints:
#  
#  1 <= k <= nums.length <= 105
#  -104 <= nums[i] <= 104
#  
# 

import random
class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        pivot = random.choice(nums)
        left = [x for x in nums if x < pivot]
        mid = [x for x in nums if x == pivot]
        right = [x for x in nums if x > pivot]

        if k <= len(right):
            return self.findKthLargest(right, k)
        elif k > len(right) + len(mid):
            return self.findKthLargest(left, k - len(right) - len(mid))
        else:
            return mid[0]

import heapq
class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        heap = []

        for n in nums:
            heapq.heappush(heap, n)
            if len(heap) > k:
                heapq.heappop(heap)

        return heap[0]

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        start = 0
        end = len(nums) - 1
        k = len(nums) - k

        while(start < end):
            mid = self.partition(nums, start, end)
            if mid < k:
                start = mid + 1
            elif mid > k:
                end = mid - 1
            else:
                break

        return nums[k]

    def partition(self, nums, start, end):
        pivot = nums[end]
        l = start
        r = end - 1
        while l <= r:
            if (nums[l] > pivot and nums[r] < pivot):
                nums[l], nums[r] = nums[r], nums[l]
            
            if nums[l] <= pivot:
                l += 1

            if nums[r] >= pivot:
                r -= 1

        nums[l], nums[end] = nums[end], nums[l]
        return l