#  Tag: Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
#   
#  Example 1:
#  
#  
#  Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
#  Output: 6
#  Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
#  
#  Example 2:
#  
#  Input: height = [4,2,0,3,2,5]
#  Output: 9
#  
#   
#  Constraints:
#  
#  n == height.length
#  1 <= n <= 2 * 104
#  0 <= height[i] <= 105
#  
#  

class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        left = [0 for i in range(n)]
        right = [0 for i in range(n)]

        for i in range(1, n):
            left[i] = max(left[i - 1], height[i - 1])

        for i in range(n - 2, -1, -1):
            right[i] = max(right[i + 1], height[i + 1])

        res = 0
        for i in range(1, n - 1):
            h = min(left[i], right[i]) - height[i]
            if h > 0:
                res += h

        return res
        
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n < 3:
            return 0

        left = 0
        right = n - 1
        left_max = height[left]
        right_max = height[right]

        res = 0
        while left <= right:
            if left_max <= right_max:
                res += max(0, left_max - height[left])
                left_max = max(left_max, height[left])  
                left += 1
            else:
                res += max(0, right_max - height[right])
                right_max = max(right_max, height[right])
                right -= 1
        return res    

class Solution:
    def trap(self, height: List[int]) -> int:
        stack = []
        res = 0

        for i in range(len(height)):
            while stack and height[i] > height[stack[-1]]:
                cur = stack.pop() 
                if stack:
                    distance = i - stack[-1] - 1
                    h = min(height[i], height[stack[-1]]) - height[cur]
                    res += distance * h

            stack.append(i)

        return res         
