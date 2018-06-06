# Your runtime beats 42.1 % of python submissions
class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        results = []
        if len(nums) < 4:
            return results
        
        nums.sort()
        
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            for j in range(i + 1, len(nums)):
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue

                start = j + 1
                end = len(nums) - 1
                twoSum = target - nums[i] - nums[j]

                while (start < end):
                    if nums[start] + nums[end] == twoSum:
                        results.append([nums[i], nums[j], nums[start], nums[end]])

                        while(start < end and nums[start] == nums[start + 1]):
                            start += 1

                        while(start < end and nums[end] == nums[end - 1]):
                            end -= 1

                        start += 1
                        end -= 1

                    elif nums[start] + nums[end] > twoSum:
                        end -= 1
                    else:
                        start += 1

        return results