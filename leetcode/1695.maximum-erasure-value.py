#  Tag: Array, Hash Table, Sliding Window
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/avwe1VdqZ-E

#  You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.
#  Return the maximum score you can get by erasing exactly one subarray.
#  An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).
#   
#  Example 1:
#  
#  Input: nums = [4,2,4,5,6]
#  Output: 17
#  Explanation: The optimal subarray here is [2,4,5,6].
#  
#  Example 2:
#  
#  Input: nums = [5,2,1,2,5,2,1,2,5]
#  Output: 8
#  Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  1 <= nums[i] <= 104
#  
#  

class Solution:
    def maximumUniqueSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        i = 0
        tmp = 0
        seen = set()
        for j in range(n):
            while nums[j] in seen:
                seen.remove(nums[i])
                tmp -= nums[i]
                i += 1

            tmp += nums[j]
            seen.add(nums[j])

            res = max(res, tmp)

        return res