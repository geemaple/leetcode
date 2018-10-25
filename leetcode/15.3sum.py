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

            self.twoSum(nums, i + 1, nums[i], 0, results)
            
        return results

    def twoSum(self, nums, left, one, target, results):
        
        right = len(nums) - 1

        while(left < right):
            val = one + nums[left] + nums[right]
            if val == target:
                results.append([one, nums[left], nums[right]])
                left += 1
                right -= 1

                while(left < right and nums[right] == nums[right + 1]):
                        right -= 1

                while(left < right and nums[left] == nums[left - 1]):
                        left += 1
         
            elif val < target:
                left += 1
            else:
                right -= 1