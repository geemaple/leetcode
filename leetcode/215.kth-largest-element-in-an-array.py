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

        while(start < end):
            mid = self.partition(nums, start, end)
            if mid < k:
                start = mid + 1
            elif mid > k:
                end = mid - 1
            else:
                break

        return nums[k]
        
    def partition(self, nums, start, end):
        k = random.randint(start, end)
        nums[k], nums[end] = nums[end], nums[k]

        k = start
        for i in range(start, end + 1):
            if nums[i] < nums[end]:
                nums[k], nums[i] = nums[i], nums[k]
                k += 1

        nums[k], nums[end] = nums[end], nums[k]
        return k