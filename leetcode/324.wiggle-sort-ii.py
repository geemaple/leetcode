class Solution(object):
    def wiggleSort(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        arr = sorted(nums)
        
        for i in range(1, len(nums), 2):
            nums[i] = arr.pop()
            
        for i in range(0, len(nums), 2):
            nums[i] = arr.pop()