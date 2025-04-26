#  Tag: Array, Queue, Sliding Window, Monotonic Queue
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/N1kAIbVPb3Q

#  You are given an integer array nums and two integers minK and maxK.
#  A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
#  
#  The minimum value in the subarray is equal to minK.
#  The maximum value in the subarray is equal to maxK.
#  
#  Return the number of fixed-bound subarrays.
#  A subarray is a contiguous part of an array.
#   
#  Example 1:
#  
#  Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
#  Output: 2
#  Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
#  
#  Example 2:
#  
#  Input: nums = [1,1,1,1], minK = 1, maxK = 1
#  Output: 10
#  Explanation: Every subarray of nums is a fixed-bound subarray. There are 10 possible subarrays.
#  
#   
#  Constraints:
#  
#  2 <= nums.length <= 105
#  1 <= nums[i], minK, maxK <= 106
#  
#  

class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        n = len(nums)
        res = 0
        i = 0
        jmin = jmax = -1
        for j in range(n):
            if nums[j] < minK or nums[j] > maxK:
                i = j + 1
            
            if nums[j] == minK:
                jmin = j

            if nums[j] == maxK:
                jmax = j

            res += max(0, min(jmin, jmax) - i + 1)

        return res
            