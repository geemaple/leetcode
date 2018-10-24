class Solution:
    """
    @param nums: An integer array
    @return: nothing
    """
    def recoverRotatedSortedArray(self, nums):
        # write your code here
        if len(nums) == 0:
            return
        
        offset = self.findMin(nums)

        if offset == 0:
            return 0
        
        self.reverse(nums, 0, offset - 1)
        self.reverse(nums, offset, len(nums) - 1)
        self.reverse(nums, 0, len(nums) - 1)
    
    def findMin(self, nums):
        start = 0
        end = len(nums) - 1
        
        while (start + 1 < end):
            mid = start + (end - start) // 2
            
            if (nums[mid] < nums[end]):
                end = mid
            elif (nums[mid] > nums[end]):
                start = mid
            else:
                end -= 1
        
        return start if nums[start] < nums[end] else end
                
        
    def reverse(self, nums, start, end):
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1