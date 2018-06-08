class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        
        start = 0
        end = len(nums) - 1
        i = 0

        while (i <= end):
            if (nums[i] == 0):
                nums[i], nums[start] = nums[start], nums[i]
                start += 1
                i += 1
            elif (nums[i] == 2):
                nums[i], nums[end] = nums[end], nums[i]
                end -= 1
            else:
                i += 1
                
# two loop
class Solution2(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        
        start = 0
        for i in range(len(nums)):
            if nums[i] < 1:
                nums[i], nums[start] = nums[start], nums[i]
                start += 1

        start = 0
        for i in range(len(nums)):
            if nums[i] < 2:
                nums[i], nums[start] = nums[start], nums[i]
                start += 1        
