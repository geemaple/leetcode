#  Tag: Array, Stack, Monotonic Stack
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
#   
#  Example 1:
#  
#  
#  Input: heights = [2,1,5,6,2,3]
#  Output: 10
#  Explanation: The above is a histogram where width of each bar is 1.
#  The largest rectangle is shown in the red area, which has an area = 10 units.
#  
#  Example 2:
#  
#  
#  Input: heights = [2,4]
#  Output: 4
#  
#   
#  Constraints:
#  
#  1 <= heights.length <= 105
#  0 <= heights[i] <= 104
#  
#  

class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        heights = heights + [-1] # 0 is ok 
        n = len(heights)
        stack = []
        res = 0

        for i in range(n):
            while len(stack) > 0 and heights[i] < heights[stack[-1]]:
                index = stack.pop()
                left = 0 if len(stack) == 0 else stack[-1] + 1
                area = (i - left) * heights[index]
                res = max(res, area)
                
            stack.append(i)

        return res
        