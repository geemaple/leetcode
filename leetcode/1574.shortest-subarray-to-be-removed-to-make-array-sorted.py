#  Tag: Array, Two Pointers, Binary Search, Stack, Monotonic Stack
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer array arr, remove a subarray (can be empty) from arr such that the remaining elements in arr are non-decreasing.
#  Return the length of the shortest subarray to remove.
#  A subarray is a contiguous subsequence of the array.
#   
#  Example 1:
#  
#  Input: arr = [1,2,3,10,4,2,3,5]
#  Output: 3
#  Explanation: The shortest subarray we can remove is [10,4,2] of length 3. The remaining elements after that will be [1,2,3,3,5] which are sorted.
#  Another correct solution is to remove the subarray [3,10,4].
#  
#  Example 2:
#  
#  Input: arr = [5,4,3,2,1]
#  Output: 4
#  Explanation: Since the array is strictly decreasing, we can only keep a single element. Therefore we need to remove a subarray of length 4, either [5,4,3,2] or [4,3,2,1].
#  
#  Example 3:
#  
#  Input: arr = [1,2,3]
#  Output: 0
#  Explanation: The array is already non-decreasing. We do not need to remove any elements.
#  
#   
#  Constraints:
#  
#  1 <= arr.length <= 105
#  0 <= arr[i] <= 109
#  
#  

class Solution:
    def findLengthOfShortestSubarray(self, arr: List[int]) -> int:
        n = len(arr)
        l = 0
        r = n - 1

        while l < r and arr[l] <= arr[l + 1]:
            l += 1

        while l < r and arr[r] >= arr[r - 1]:
            r -= 1

        if l >= r:
            return 0

        res = min(n - l - 1, r)
        i = 0
        j = r
        while i <= l and j <= n - 1:
            if arr[i] <= arr[j]:
                res = min(res, j - i - 1)
                i += 1
            else:
                j += 1

        return res