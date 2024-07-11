#  Tag: Array, Dynamic Programming, Binary Search
#  Time: O(N*logN)
#  Space: O(N)
#  Ref: -
#  Note: LIS | std::lower_bound

#  Given an integer array nums, return the length of the longest strictly increasing subsequence.
#   
#  Example 1:
#  
#  Input: nums = [10,9,2,5,3,7,101,18]
#  Output: 4
#  Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
#  
#  Example 2:
#  
#  Input: nums = [0,1,0,3,2,3]
#  Output: 4
#  
#  Example 3:
#  
#  Input: nums = [7,7,7,7,7,7,7]
#  Output: 1
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 2500
#  -104 <= nums[i] <= 104
#  
#   
#  Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?
#  

class Solution:
    # https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
    def lengthOfLIS(self, nums: List[int]) -> int:
        res = []
        for n in nums:
            index = self.lower_bound(res, n)
            if index < len(res):
                res[index] = n
            else:
                res.append(n)

        return len(res)


    def lower_bound(self, nums: List[int], target: int) -> int:
        # find the smallest index >= target
        start = 0
        end = len(nums)

        while start < end:
            mid = start + (end - start) // 2

            if nums[mid] < target:
                start = mid + 1
            else:
                end = mid

        return start

class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1 for i in range(n)]

        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j] and dp[j] + 1 > dp[i]:
                    dp[i] = dp[j] + 1

        return max(dp)