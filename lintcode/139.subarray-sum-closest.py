class Solution:
    """
    @param: nums: A list of integers
    @return: A list of integers includes the index of the first number and the index of the last number
    """
    def subarraySumClosest(self, nums):
        # write your code here
        prefix_sum = [[0, -1]]
        for i in range(len(nums)):
            tmp = [nums[i] + prefix_sum[-1][0], i]
            prefix_sum.append(tmp)
            
        prefix_sum.sort()
        
        closest = float('inf')
        ans = []
        
        for i in range(1, len(prefix_sum)):
            if abs(prefix_sum[i][0] - prefix_sum[i - 1][0]) < closest:
                closest = abs(prefix_sum[i][0] - prefix_sum[i - 1][0])
                left = min(prefix_sum[i][1], prefix_sum[i - 1][1]) + 1
                right = max(prefix_sum[i][1], prefix_sum[i - 1][1])
                ans = [left, right]
                
        return ans