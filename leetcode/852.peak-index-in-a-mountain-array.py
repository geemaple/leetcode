#  Tag: Array, Binary Search
#  Time: O(logN)
#  Space: O(1)
#  Ref: -
#  Note: Mountain

#  An array arr is a mountain if the following properties hold:
#  
#  arr.length >= 3
#  There exists some i with 0 < i < arr.length - 1 such that:
#  	
#  arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
#  arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
#  
#  
#  
#  Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].
#  You must solve it in O(log(arr.length)) time complexity.
#   
#  Example 1:
#  
#  Input: arr = [0,1,0]
#  Output: 1
#  
#  Example 2:
#  
#  Input: arr = [0,2,1,0]
#  Output: 1
#  
#  Example 3:
#  
#  Input: arr = [0,10,5,2]
#  Output: 1
#  
#   
#  Constraints:
#  
#  3 <= arr.length <= 105
#  0 <= arr[i] <= 106
#  arr is guaranteed to be a mountain array.
#  
#  

class Solution(object):
    def peakIndexInMountainArray(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        start = 0
        end = len(arr) - 1

        while start < end:

            mid = start + (end - start) // 2

            if arr[mid] > [mid + 1]:
                end = mid
            else:
                start = mid + 1

        return start 