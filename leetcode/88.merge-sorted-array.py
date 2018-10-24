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
        cur = len(nums1) - 1
        
        while left >= 0 or right >= 0:
            left_val = nums1[left] if left >= 0 else float('-inf')
            right_val = nums2[right] if right >= 0 else float('-inf')
            
            if (left_val > right_val):
                nums1[cur] = left_val
                left -= 1
            else:
                nums1[cur] = right_val
                right -= 1
                
            cur -= 1