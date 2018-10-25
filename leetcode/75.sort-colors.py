# counting sort

number_of_colors = 3
class Solution(object):
    def sortColors(self, nums):
        counting = [0 for i in range(number_of_colors)]

        for n in nums:
            counting[n] += 1

        for i in range(1, number_of_colors):
            counting[i] += counting[i - 1]

        tmp = [0 for i in range(len(nums))]
        for i in range(len(nums)):
            count = counting[nums[i]]
            tmp[count - 1] = nums[i]
            counting[nums[i]] -= 1

        for i in range(len(nums)):
            nums[i] = tmp[i]
        

# two loop
class Solution2(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        k = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                nums[i], nums[k] = nums[k], nums[i]
                k += 1
                
        for i in range(k, len(nums)):
            if nums[i] == 1:
                nums[i], nums[k] = nums[k], nums[i]
                k += 1           
            if nums[i] < 2:
                nums[i], nums[start] = nums[start], nums[i]
                start += 1        
