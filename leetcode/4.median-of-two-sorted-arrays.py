class Solution(object):
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
        