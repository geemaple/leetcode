class Solution:
    """
    @param nums: The integer array you should partition
    @param k: An integer
    @return: The index after partition
    """
    def partitionArray(self, nums, k):
        # write your code here
        target = 0
        for i in range(len(nums)):
            if nums[i] < k:
                nums[i], nums[target] = nums[target], nums[i]
                target += 1

        return target