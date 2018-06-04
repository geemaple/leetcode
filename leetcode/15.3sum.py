class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        results = []
        target = 0
        nums.sort()

        for i in range(len(nums) - 1):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            new_target = target - nums[i]

            self.twoSum(nums, i + 1, len(nums) - 1, new_target, results)
            
        return results

    def twoSum(self, nums, left, right, target, results):
        
        while(left < right):
            if nums[left] + nums[right] == target:
                results.append([-target, nums[left], nums[right]])
                left += 1
                right -= 1

                while(left < right and nums[right] == nums[right + 1]):
                        right -= 1

                while(left < right and nums[left] == nums[left - 1]):
                        left += 1
         
            elif nums[left] + nums[right] < target:
                left += 1
            else:
                right -= 1