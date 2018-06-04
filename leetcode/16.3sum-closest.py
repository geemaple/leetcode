# Your runtime beats 7.47 % of python submissions
class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        result = None
        nums.sort()
        
        for i in range(len(nums)):
            left = i + 1
            right = len(nums) - 1

            while (left < right):
                tmp = nums[left] + nums[right] + nums[i]
                if result is None or abs(tmp - target) < abs(target - result):
                    result = tmp

                if tmp > target:
                    right -= 1
                else:
                    left += 1

        return result