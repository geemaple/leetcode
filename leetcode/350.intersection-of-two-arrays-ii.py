# hash
class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        count_map = {}
        res = []
        for num in nums1:
            count_map[num] = count_map.get(num, 0) + 1

        for num in nums2:
            if count_map.get(num, 0) > 0:
                res.append(num)
                count_map[num] -= 1

        return res


# tow-pointers
class Solution2(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
        nums1.sort()
        nums2.sort()

        left = 0
        right = 0
        res = []
        while(left < len(nums1) and right < len(nums2)):
            if nums1[left] > nums2[right]:
                right += 1
            elif nums1[left] < nums2[right]:
                left += 1
            else:
                res.append(nums1[left])
                left += 1
                right += 1

        return res