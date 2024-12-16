#  Tag: Array, Binary Search, Dynamic Programming, Sliding Window, Rolling Hash, Hash Function
#  Time: O(NM)
#  Space: O(NM)
#  Ref: -
#  Note: -

#  Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.
#   
#  Example 1:
#  
#  Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
#  Output: 3
#  Explanation: The repeated subarray with maximum length is [3,2,1].
#  
#  Example 2:
#  
#  Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
#  Output: 5
#  Explanation: The repeated subarray with maximum length is [0,0,0,0,0].
#  
#   
#  Constraints:
#  
#  1 <= nums1.length, nums2.length <= 1000
#  0 <= nums1[i], nums2[i] <= 100
#  
#  

class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        m = len(nums2)

        # left to right
        dp = [[0] * (m + 1) for i in range(n + 1)]

        res = 0
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if nums1[i - 1] == nums2[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                    res = max(res, dp[i][j])

        return res

class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        n = len(nums1)
        m = len(nums2)

        # right to left
        dp = [[0] * (m + 1) for i in range(n + 1)]

        res = 0
        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                if nums1[i] == nums2[j]:
                    dp[i][j] = 1 + dp[i + 1][j + 1]
                    res = max(res, dp[i][j])

        return res

class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        def has_common_subarray(length):
            seen = set()
            hash1, base, mod = 0, 101, 10**9 + 7

            # Compute hash for the first window of length in nums1
            for i in range(length):
                hash1 = (hash1 * base + nums1[i]) % mod
            seen.add(hash1)

            # Slide the window in nums1
            baseL = pow(base, length, mod)
            for i in range(length, len(nums1)):
                hash1 = (hash1 * base - nums1[i - length] * baseL + nums1[i]) % mod
                seen.add(hash1)

            # Compute hash for nums2 and check in seen
            hash2 = 0
            for i in range(length):
                hash2 = (hash2 * base + nums2[i]) % mod
            if hash2 in seen:
                return True

            for i in range(length, len(nums2)):
                hash2 = (hash2 * base - nums2[i - length] * baseL + nums2[i]) % mod
                if hash2 in seen:
                    return True

            return False

        left, right = 0, min(len(nums1), len(nums2))
        result = 0
        while left < right:
            mid = left +  (right - left) // 2 + 1
            if has_common_subarray(mid):
                result = mid
                left = mid
            else:
                right = mid - 1

        return result