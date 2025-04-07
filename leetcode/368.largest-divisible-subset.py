#  Tag: Array, Math, Dynamic Programming, Sorting
#  Time: O(N^2)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/1Rk51qxHSl0

#  Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:
#  
#  answer[i] % answer[j] == 0, or
#  answer[j] % answer[i] == 0
#  
#  If there are multiple solutions, return any of them.
#   
#  Example 1:
#  
#  Input: nums = [1,2,3]
#  Output: [1,2]
#  Explanation: [1,3] is also accepted.
#  
#  Example 2:
#  
#  Input: nums = [1,2,4,8]
#  Output: [1,2,4,8]
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 1000
#  1 <= nums[i] <= 2 * 109
#  All the integers in nums are unique.
#  
#  

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        n = len(nums)
        nums.sort()
        table = [1 for _ in range(n)]
        ans = [-1 for _ in range(n)]
        
        index = 0
        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0 and table[j] + 1 > table[i]:
                    table[i] = table[j] + 1
                    ans[i] = j
                    
            if table[i] > table[index]:
                index = i
                
        result = []
        while(index != -1):
            result.append(nums[index])
            index = ans[index]
            
        return result