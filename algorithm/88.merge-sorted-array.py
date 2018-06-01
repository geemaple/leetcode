class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: void Do not return anything, modify nums1 in-place instead.
        """
        
        left = m - 1
        right = n - 1
        total = m + n - 1

        while (left >= 0 and right >= 0):
            if nums1[left] < nums2[right]:
                nums1[total] = nums2[right]
                right -= 1
            else:
                nums1[total] = nums1[left]
                left -= 1
            total -= 1
        
        while (right >= 0):
            nums1[total] = nums2[right]
            right -= 1
            total -= 1