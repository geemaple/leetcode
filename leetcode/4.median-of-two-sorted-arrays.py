class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        n = len(nums1) + len(nums2)
        is_two = (n % 2 == 0)

        if is_two:
            return (self.find_kth_number(nums1, 0, nums2, 0, n/2) + 
            self.find_kth_number(nums1, 0, nums2, 0, n/2 + 1)) / 2.0

        return self.find_kth_number(nums1, 0, nums2, 0, n/2 + 1)


    # the target is to find the kth number which k = median
    # each step we can get rid of half of k
    def find_kth_number(self, nums1, start1, nums2, start2, k):
        if start1 >= len(nums1):
            return float(nums2[start2 + k - 1])

        if start2 >= len(nums2):
            return float(nums1[start1 + k - 1])

        if k == 1:
            return float(min(nums1[start1], nums2[start2]))

        left_half_k = start1 + k / 2 - 1
        left = nums1[left_half_k] if left_half_k < len(nums1) else float("inf")

        right_half_k = start2 + k / 2 - 1
        right = nums2[right_half_k] if right_half_k < len(nums2) else float("inf")
        
        if left < right:
            return self.find_kth_number(nums1, start1 + k / 2, nums2, start2, k - k / 2)
        else:
            return self.find_kth_number(nums1, start1, nums2, start2 + k / 2, k - k / 2)