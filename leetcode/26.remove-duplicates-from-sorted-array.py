class Solution(object):
    def removeDuplicates(self, nums: List[int]) -> int:        
        i = 0
        for j in range(len(nums)):
            if (i == 0 or nums[i - 1] < nums[j]):
                nums[i] = nums[j]
                i += 1

        return i


class Solution2:
    def removeDuplicates(self, nums: List[int]) -> int:
        
        slow = fast = 0
        
        while fast < len(nums):
                        
            while fast + 1 < len(nums) and nums[fast] == nums[fast + 1]:
                fast += 1
            
            if nums[slow] < nums[fast]:
                nums[slow], nums[fast] = nums[fast], nums[slow]
            
            slow += 1
            fast += 1
            
        return slow