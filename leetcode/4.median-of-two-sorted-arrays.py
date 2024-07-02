#  Tag: Array, Binary Search, Divide and Conquer
#  Time: -
#  Space: -
#  Ref: -
#  Note: -

#  Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
#  The overall run time complexity should be O(log (m+n)).
#   
#  Example 1:
#  
#  Input: nums1 = [1,3], nums2 = [2]
#  Output: 2.00000
#  Explanation: merged array = [1,2,3] and median is 2.
#  
#  Example 2:
#  
#  Input: nums1 = [1,2], nums2 = [3,4]
#  Output: 2.50000
#  Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
#  
#   
#  Constraints:
#  
#  nums1.length == m
#  nums2.length == n
#  0 <= m <= 1000
#  0 <= n <= 1000
#  1 <= m + n <= 2000
#  -106 <= nums1[i], nums2[i] <= 106
#  
#  

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        k = len(nums1) + len(nums2)
        if (k % 2 == 1):
            return self.find_kth_num(nums1, 0, nums2, 0, (k + 1) // 2)
        else:
            return (self.find_kth_num(nums1, 0, nums2, 0, k // 2) + self.find_kth_num(nums1, 0, nums2, 0, k // 2 + 1)) / 2.0
        
        
    def find_kth_num(self, nums1, i, nums2, j, k):
        if i == len(nums1):
            return nums2[j + k - 1]
        
        if j == len(nums2):
            return nums1[i + k - 1]
        
        if k == 1:
            return min(nums1[i], nums2[j])
        
        left = nums1[i + k // 2 - 1] if i + k // 2 - 1 < len(nums1) else float('inf')
        right = nums2[j + k // 2 - 1] if j + k // 2 - 1 < len(nums2) else float('inf')
        
        if left <= right:
            return self.find_kth_num(nums1, i + k // 2, nums2, j, k - k // 2)
        else:
            return self.find_kth_num(nums1, i, nums2, j + k // 2, k - k // 2)

class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        k = len(nums1) + len(nums2)

        i = 0
        j = 0
        pre = 0
        cur = 0
        for _ in range(k // 2 + 1):
            pre = cur
            if i < len(nums1) and j < len(nums2):
                if nums1[i] >= nums2[j]:
                    cur = nums2[j]
                    j += 1
                else:
                    cur = nums1[i]
                    i += 1
            elif i < len(nums1):
                cur = nums1[i]
                i += 1
            else:
                cur = nums2[j]
                j += 1 

        return cur if (k % 2 == 1) else (pre + cur) / 2