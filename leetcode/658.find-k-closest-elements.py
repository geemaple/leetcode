# log(N - K) and O(1)
class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        
        if k >= len(arr):
            return arr
        
        start = 0
        end = len(arr) - k

        while start < end:
            
            mid = start + (end - start) // 2
            
            if abs(arr[mid] - x) <= abs(arr[mid + k] - x):
                end = mid
            else:
                start = mid + 1

        return arr[start: start + k]

# O(N) and O(1)
class Solution1(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        
        if k >= len(arr):
            return arr
        
        start = 0
        end = len(arr) - 1

        while end - start + 1 > k:
            if abs(arr[start] - x) <= abs(arr[end] - x):
                end -= 1
            else:
                start += 1

        return arr[start: end + 1]
