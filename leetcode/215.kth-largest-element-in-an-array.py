from random import randint
class Solution(object):
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        start = 0
        end = len(nums) - 1
        k = len(nums) - k

        while (start <= end):
            pos = self.partition(nums, start, end)

            if k == pos:
                break
            if (pos < k):
                start = pos + 1
            else:
                end = pos - 1
                
        return nums[k]

    def partition(self, nums, start, end):
        index = randint(start, end)

        nums[end], nums[index] = nums[index], nums[end]

        k = start
        for i in range(start, end):
            if nums[i] <= nums[end]:
                nums[i], nums[k] = nums[k], nums[i]
                k += 1

        nums[end], nums[k] = nums[k], nums[end]
        return k