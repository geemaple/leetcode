class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        count = len(nums1) + len(nums2)
        if count == 0:
            return 0.0
        
        if count % 2 == 0:
            res = self.findKth(count / 2, nums1, 0, nums2, 0)
            res += self.findKth(count / 2 + 1, nums1, 0, nums2, 0)
            return float(res / 2.0)
        else:
            res = self.findKth((count + 1) / 2, nums1, 0, nums2, 0)
            return float(res)
        
    def findKth(self, k, nums1, start1, nums2, start2):
        
        if start1 >= len(nums1):
            return nums2[start2 + k - 1]
        
        if start2 >= len(nums2):
            return nums1[start1 + k - 1]
        
        if k == 1:
            return min(nums1[start1], nums2[start2])
        
        half = k // 2
        val1 = nums1[half + start1 - 1] if half + start1 - 1 < len(nums1) else float('inf')
        val2 = nums2[half + start2 - 1] if half + start2 - 1 < len(nums2) else float('inf')
        
        if val1 < val2:
            return self.findKth(k - half, nums1, start1 + half, nums2, start2)
        else:
            return self.findKth(k - half, nums1, start1, nums2, start2 + half)
            