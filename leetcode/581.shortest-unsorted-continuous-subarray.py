#  Tag: Array, Two Pointers, Stack, Greedy, Sorting, Monotonic Stack
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer array nums, you need to find one continuous subarray such that if you only sort this subarray in non-decreasing order, then the whole array will be sorted in non-decreasing order.
#  Return the shortest such subarray and output its length.
#   
#  Example 1:
#  
#  Input: nums = [2,6,4,8,10,9,15]
#  Output: 5
#  Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
#  
#  Example 2:
#  
#  Input: nums = [1,2,3,4]
#  Output: 0
#  
#  Example 3:
#  
#  Input: nums = [1]
#  Output: 0
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 104
#  -105 <= nums[i] <= 105
#  
#   
#  Follow up: Can you solve it in O(n) time complexity?

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        r = -1
        biggest = nums[0]
        for i in range(1, n):
            if biggest > nums[i]:
                r = i
            else:
                biggest = nums[i]

        smallest = nums[-1]
        l = 0
        for i in range(n - 2, -1, -1):
            if smallest < nums[i]:
                l = i
            else:
                smallest = nums[i]

        return r - l + 1

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        stack = []
        l = n - 1
        for i in range(n):
            while len(stack) > 0 and nums[stack[-1]] > nums[i]:
                stack.pop()
                l = min(l, stack[-1] if len(stack) > 0 else -1)

            stack.append(i)

        if l == n - 1:
            return 0
        
        stack = []
        r = 0
        for i in range(n - 1, -1, -1):
            while len(stack) > 0 and nums[stack[-1]] < nums[i]:
                stack.pop()
                r = max(r, stack[-1] if len(stack) > 0 else n)

            stack.append(i)

        return r - l - 1