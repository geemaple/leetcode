class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        start = 0
        end = len(nums) - 1

        while(start + 1 < end):
            mid = start + (end - start) / 2
            if nums[mid] > nums[end]:
                start = mid
            else:
                end = mid

        if nums[start] > nums[end]:
            return nums[end]
        else:
            return nums[start]