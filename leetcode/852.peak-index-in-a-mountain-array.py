class Solution(object):
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        start = 0
        end = len(A) - 1

        while (start + 1 < end):
            mid = start + (end - start) / 2

            if (A[mid] > A[mid + 1]):
                end = mid
            else:
                start = mid

        return start if A[start] > A[end] else end
