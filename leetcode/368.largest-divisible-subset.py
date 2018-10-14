# f[i] = max(f[j] + 1) where nums[i] % nums[j] == 0
class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        if nums is None or len(nums) == 0:
            return []
        
        nums.sort()
        table = [1 for _ in range(len(nums))]
        ans = [-1 for _ in range(len(nums))]
        
        index = 0
        longest = 1
        
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0 and table[j] + 1 > table[i]:
                    table[i] = table[j] + 1
                    ans[i] = j
                    
            if table[i] > longest:
                longest = table[i]
                index = i
                
        result = []
        while(index != -1):
            result.append(nums[index])
            index = ans[index]
            
        return result