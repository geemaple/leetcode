class Solution(object):
    def maximalRectangle(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if matrix is None or len(matrix) == 0 or len(matrix[0]) == 0:
            return 0
        
        m = len(matrix)
        n = len(matrix[0])
        
        nums = [0 for _ in range(n + 1)]
        
        res = 0
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == '1':
                    nums[j] += 1
                else:
                    nums[j] = 0
                    
            res = max(res, self.maxArea(nums))
            
        return res
                    
    def maxArea(self, nums):
        nums[-1] = -1
        stack = []
        
        res = 0
        for i in range(len(nums)):
            while stack and nums[stack[-1]] >= nums[i]:
                index = stack.pop()
                left = stack[-1] if stack else -1
                width = i - left + 1 - 2
                
                res = max(res, width * nums[index])
                
            stack.append(i)
            
        return res
