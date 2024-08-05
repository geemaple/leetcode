from typing import List
class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        
        n = len(nums)
        res = [-1 for i in range(n)]
        stack = []
        nums = nums

        for i in range(n):
            while len(stack) > 0 and nums[i] > nums[stack[-1]]:
                j = stack[-1]
                stack.pop()
                res[j] = nums[i]

            stack.append(i)

        return res

s = Solution()
res = s.nextGreaterElements([3,2,1,2,4,5])
print(res)