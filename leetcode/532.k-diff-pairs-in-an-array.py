class Solution(object):
    def findPairs(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        nums.sort()
        
        res = 0
        left = 0
        right = 0

        while (right < len(nums)):

            while(left < right and nums[right] - nums[left] >= k):
                
                if (nums[right] - nums[left] == k):
                    res += 1

                    while(left + 1 < len(nums) and nums[left] == nums[left + 1]):
                        left += 1

                left += 1

            right = max(left, right)
            right += 1
                    
        return res
