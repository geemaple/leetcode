class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        map = dict()
        for i in range(len(nums)):
            val = target - nums[i]
            if val in map:
                return [map[val], i]
            else:
                map[nums[i]] = i