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