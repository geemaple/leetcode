#
# @lc app=leetcode id=4 lang=python
#
# [4] Median of Two Sorted Arrays
#
# https://leetcode.com/problems/median-of-two-sorted-arrays/description/
#
# algorithms
# Hard (28.77%)
# Total Accepted:    644.1K
# Total Submissions: 2.2M
# Testcase Example:  '[1,3]\n[2]'
#
# There are two sorted arrays nums1 and nums2 of size m and n respectively.
# 
# Find the median of the two sorted arrays. The overall run time complexity
# should be O(log (m+n)).
# 
# You may assume nums1 and nums2 cannot be both empty.
# 
# Example 1:
# 
# 
# nums1 = [1, 3]
# nums2 = [2]
# 
# The median is 2.0
# 
# 
# Example 2:
# 
# 
# nums1 = [1, 2]
# nums2 = [3, 4]
# 
# The median is (2 + 3)/2 = 2.5
# 
# 
#
# log(min(M, N))
class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """   
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
            
        m = len(nums1)
        n = len(nums2)
        
        start = 0
        end = m
        
        while (start <= end):
            mid = start + (end - start) // 2
            leftNums1 = nums1[mid - 1] if mid >= 1 else float('-inf')
            rightNums1 = nums1[mid] if mid < len(nums1) else float('inf')
            
            anchor = (m + n) // 2 - mid
            leftNums2 = nums2[anchor - 1] if anchor >= 1 else float('-inf')
            rightNums2 = nums2[anchor] if anchor < len(nums2) else float('inf')

            if leftNums1 <= rightNums2 and leftNums2 <= rightNums1:
                if (m + n) % 2 == 1:
                    return min(rightNums1, rightNums2)
                else:
                    return (max(leftNums1, leftNums2) + min(rightNums1, rightNums2)) / 2.0
            
            if leftNums1 > rightNums2:
                end = mid - 1
            
            if leftNums2 > rightNums1:
                start = mid + 1
                
class Solution2(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        count = len(nums1) + len(nums2)
        if (count % 2 == 1):
            return self.find_kth_num(nums1, 0, nums2, 0, (count + 1) // 2)
        else:
            mid = count // 2
            return (self.find_kth_num(nums1, 0, nums2, 0, mid) + self.find_kth_num(nums1, 0, nums2, 0, mid + 1)) / 2.0
        
        
    def find_kth_num(self, nums1, start1, nums2, start2, k):
        if start1 >= len(nums1):
            return nums2[start2 + k - 1]
        
        if start2 >= len(nums2):
            return nums1[start1 + k - 1]
        
        if k == 1:
            return min(nums1[start1], nums2[start2])
        
        half = k // 2
        left_half = nums1[start1 + half - 1] if start1 + half - 1 < len(nums1) else float('inf')
        right_half = nums2[start2 + half - 1] if start2 + half - 1 < len(nums2) else float('inf')
        
        if left_half <= right_half:
            return self.find_kth_num(nums1, start1 + half, nums2, start2, k - half)
        else:
            return self.find_kth_num(nums1, start1, nums2, start2 + half, k - half)
        

