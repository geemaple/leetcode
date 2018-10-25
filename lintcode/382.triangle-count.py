class Solution:
    """
    @param S: A list of integers
    @return: An integer
    """
    def triangleCount(self, S):
        # write your code here
        S.sort()
        
        res = 0
        for i in range(len(S) - 1, -1, -1):
            res += self.counting(S, i)
            
        return res
        
    def counting(self, nums, longestIndex):
        start = 0
        end = longestIndex - 1
        count = 0
        
        while (start < end):
            
            while (start < end and nums[start] + nums[end] > nums[longestIndex]):
                count += end - start
                end -= 1
            else:
                start += 1
                
        return count