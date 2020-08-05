class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        
        slow = 0
        for fast in range(len(nums)):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
        
        return slow
        

class Solution2:
    def removeElement(self, nums: List[int], val: int) -> int:
        
        start = 0
        end = len(nums) - 1
        
        while start <= end:
            
            if nums[start] == val:
                nums[start], nums[end] = nums[end], nums[start]
                end -= 1
            else:
                start += 1
        
        return start