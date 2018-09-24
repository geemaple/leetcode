class Solution(object):

    def searchHead(self, nums, target):
        if nums is None or len(nums) == 0:
            return -1

        start = 0
        end = len(nums) - 1

        while(start + 1 < end):
            mid = start + (end - start) / 2

            if nums[mid] > target:
                end = mid
            elif nums[mid] < target:
                start = mid
            else:
                end = mid

        if nums[start] == target:
            return start

        if nums[end] == target:
            return end

        return -1 

    def searchTail(self, nums, target):
        if nums is None or len(nums) == 0:
            return -1

        start = 0
        end = len(nums) - 1

        while(start + 1 < end):
            mid = start + (end - start) / 2

            if nums[mid] > target:
                end = mid
            elif nums[mid] < target:
                start = mid
            else:
                start = mid

        if nums[end] == target:
            return end

        if nums[start] == target:
            return start

        return -1 

    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        return [self.searchHead(nums, target), self.searchTail(nums, target)]