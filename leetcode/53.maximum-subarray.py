#  Tag: Array, Divide and Conquer, Dynamic Programming
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an integer array nums, find the subarray with the largest sum, and return its sum.
#   
#  Example 1:
#  
#  Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
#  Output: 6
#  Explanation: The subarray [4,-1,2,1] has the largest sum 6.
#  
#  Example 2:
#  
#  Input: nums = [1]
#  Output: 1
#  Explanation: The subarray [1] has the largest sum 1.
#  
#  Example 3:
#  
#  Input: nums = [5,4,-1,7,8]
#  Output: 23
#  Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  -104 <= nums[i] <= 104
#  
#   
#  Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
#  

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0 for i in range(n)]

        dp[0] = nums[0]
        for i in range(1, n):
            dp[i] = max(dp[i - 1], 0) + nums[i]

        return max(dp)


# prefix-sum
class Solution(object):
    def maxSubArray(self, nums: List[int]) -> int:
        # suppose sumTo[i] = a[0] + a[1] + ... [i - 1], sumTo(0) = 0
        # the subarray a[i:j] = sumTo[j] - sumTo[i]

        largest = float('-inf')
        smallest = 0
        sumTo = 0

        for num in nums:
            sumTo += num
            largest = max(largest, sumTo - smallest)
            smallest = min(smallest, sumTo)

        return largest