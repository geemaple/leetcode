class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """

        nums1.sort()
        nums2.sort()
        results = []
        left = 0
        right = 0
        while (left < len(nums1) and right < len(nums2)):
            if nums1[left] == nums2[right]:
                results.append(nums1[left])
                left += 1
                right += 1
            elif nums1[left] > nums2[right]:
                right += 1
            else:
                left += 1

        return results
