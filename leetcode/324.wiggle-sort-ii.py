#  Tag: Array, Divide and Conquer, Greedy, Sorting, Quickselect
#  Time: -
#  Space: -
#  Ref: -
#  Note: -

#  Given an integer array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
#  You may assume the input array always has a valid answer.
#   
#  Example 1:
#  
#  Input: nums = [1,5,1,1,6,4]
#  Output: [1,6,1,5,1,4]
#  Explanation: [1,4,1,5,1,6] is also accepted.
#  
#  Example 2:
#  
#  Input: nums = [1,3,2,2,3,1]
#  Output: [2,3,1,3,1,2]
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 5 * 104
#  0 <= nums[i] <= 5000
#  It is guaranteed that there will be an answer for the given input nums.
#  
#   
#  Follow Up: Can you do it in O(n) time and/or in-place with O(1) extra space?

class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        arr = sorted(nums)
        
        for i in range(1, n, 2):
            nums[i] = arr.pop()
            
        for i in range(0, n, 2):
            nums[i] = arr.pop()

# follow up
class Solution:
    def wiggleSort(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        left = 0
        right = n - 1
        medean = self.quick_select(nums, right // 2)

        def virtual(i:int):
            return (1 + 2 * i) % (n | 1)

        i = 0
        while i <= right:
            if nums[virtual(i)] > medean:
                nums[virtual(i)], nums[virtual(left)] = nums[virtual(left)], nums[virtual(i)]
                i += 1
                left += 1
            elif nums[virtual(i)] < medean:
                nums[virtual(i)], nums[virtual(right)] = nums[virtual(right)], nums[virtual(i)]
                right -= 1
            else:
                i += 1
    
    def quick_select(self, nums: list, k: int) -> int:
        left = 0
        right = len(nums) - 1
        while left < right:
            pick = self.partition(nums, left, right)
            if pick == k:
                break

            if pick < k:
                left = pick + 1
            else:
                right = pick - 1

        return nums[k]

    def partition(self, nums:list, left: int, right: int) -> int:
        pivot = nums[right]
        l = left
        r = right - 1

        while l <= r:
            if nums[l] > pivot and nums[r] < pivot:
                nums[l], nums[r] = nums[r], nums[l]

            if nums[l] <= pivot:
                l += 1

            if nums[r] >= pivot:
                r -= 1

        nums[l], nums[right] = nums[right], nums[l]
        return l