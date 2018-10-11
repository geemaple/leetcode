class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start = 0
        end = len(nums) - 1
        
        while (start + 1 < end):
            mid = start + (end - start) // 2
            
            if (nums[mid] > nums[mid - 1]):
                start = mid
            else:
                end = mid
                
        return start if nums[start] > nums[end] else end