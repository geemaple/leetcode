#  Tag: Array, Stack, Monotonic Stack
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
#   
#  Example 1:
#  Input: temperatures = [73,74,75,71,69,72,76,73]
#  Output: [1,1,4,2,1,1,0,0]
#  Example 2:
#  Input: temperatures = [30,40,50,60]
#  Output: [1,1,1,0]
#  Example 3:
#  Input: temperatures = [30,60,90]
#  Output: [1,1,0]
#  
#   
#  Constraints:
#  
#  1 <= temperatures.length <= 105
#  30 <= temperatures[i] <= 100
#  
#  

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        res = [0 for i in range(n)]
        stack = []

        for i in range(n):
            while len(stack) > 0 and temperatures[i] > temperatures[stack[-1]]:
                j = stack.pop()
                res[j] = i - j

            stack.append(i)

        return res