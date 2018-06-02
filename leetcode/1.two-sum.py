class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num_map = {}

        for i in range(len(nums)):
            num = nums[i]

            if target - num in num_map:
                return [num_map[target - num], i]

            num_map[num] = i

        return [None, None]