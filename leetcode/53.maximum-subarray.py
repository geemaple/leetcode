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

# follow-up
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        return self.helper(nums, 0, len(nums) - 1)
    
    def helper(self, nums: List[int], left: int, right: int) -> int:
        if left == right:
            return nums[left]
        
        mid = (left + right) // 2
        leftSum = float('-inf')
        curSum = 0
        # Maximum sum of subarray ending at mid and going left
        for i in range(mid, left - 1, -1):
            curSum += nums[i]
            leftSum = max(leftSum, curSum)
        
        rightSum = float('-inf')
        curSum = 0
        # Maximum sum of subarray starting at mid+1 and going right
        for i in range(mid + 1, right + 1):
            curSum += nums[i]
            rightSum = max(rightSum, curSum)
        
        return max(self.helper(nums, left, mid),
                   self.helper(nums, mid + 1, right),
                   leftSum + rightSum) # Max sum crossing midpoint