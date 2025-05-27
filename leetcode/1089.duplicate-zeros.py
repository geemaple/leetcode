#  Tag: Array, Two Pointers
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
#  Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
#   
#  Example 1:
#  
#  Input: arr = [1,0,2,3,0,4,5,0]
#  Output: [1,0,0,2,3,0,0,4]
#  Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
#  
#  Example 2:
#  
#  Input: arr = [1,2,3]
#  Output: [1,2,3]
#  Explanation: After calling your function, the input array is modified to: [1,2,3]
#  
#   
#  Constraints:
#  
#  1 <= arr.length <= 104
#  0 <= arr[i] <= 9
#  
#  

class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        n = len(arr)
        shift = 0
        i = 0
        while i + shift < n:
            shift += arr[i] == 0
            i += 1

        for j in range(i - 1, -1, -1):
            if j + shift < n:
                arr[j + shift] = arr[j]

            if arr[j] == 0:
                arr[j + shift - 1] = arr[j]
                shift -= 1