class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """

        if nums is None or len(nums) == 0:
            return False

        start = 0
        end = len(nums) - 1

        while(start + 1 < end):
            mid = start + (end - start) / 2

            if target == nums[mid]:
                return True

            if nums[mid] < nums[end]:
                if nums[mid] < target and target <= nums[end]:
                    start = mid
                else:
                    end = mid

            elif nums[mid] > nums[end]:
                if nums[end] < target and target < nums[mid]:
                    end = mid
                else:
                    start = mid

            else:
                end -= 1

        return (nums[start] == target or nums[end] == target)
