class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        
        # 1. use a set to test if exist O(N + M)
        # 2. use binary search to find if exist O(NlogN) + O(MlogN) = O((N + M) * logN)
        # 3. sort left and right, and merge it O(NLogN) + O(MlogM) + min(M, N)

        set1 = set(nums1)
        set2 = set(nums2)

        return list(set1.intersection(set2))

# two-pointers
class Solution2(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        if nums1 is None or nums2 is None:
            return []

        nums1.sort()
        nums2.sort()

        ans = []
        left = 0
        right = 0

        while (left < len(nums1) and right < len(nums2)):
            if (nums1[left] < nums2[right]):
                left += 1
            elif (nums1[left] > nums2[right]):
                right += 1
            else:
                ans.append(nums1[left])

                while (left + 1 < len(nums1) and nums1[left] == nums1[left + 1]):
                    left += 1

                while (right + 1 < len(nums2) and nums2[right] == nums2[right + 1]):
                    right += 1

                left += 1
                right += 1

        return ans
