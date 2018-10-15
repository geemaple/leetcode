class Solution(object):
    def largestRectangleArea(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        stack = []
        nums = heights[:] + [-1]
        res = 0
        
        for i in range(len(nums)):
            
            while(stack and nums[stack[-1]] >= nums[i]):
                index = stack.pop()
                left = stack[-1] if stack else -1
                width = i - left + 1 - 2
                res = max(res, width * heights[index])
            
            stack.append(i)
            
        return res