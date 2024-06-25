#  Tag: Array, Two Pointers, Binary Search, Sorting, Sliding Window, Heap (Priority Queue)
#  Time: O(Log(N - K))
#  Space: O(1)
#  Ref: -
#  Note: Range

#  Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. The result should also be sorted in ascending order.
#  An integer a is closer to x than an integer b if:
#  
#  |a - x| < |b - x|, or
#  |a - x| == |b - x| and a < b
#  
#   
#  Example 1:
#  Input: arr = [1,2,3,4,5], k = 4, x = 3
#  Output: [1,2,3,4]
#  Example 2:
#  Input: arr = [1,2,3,4,5], k = 4, x = -1
#  Output: [1,2,3,4]
#  
#   
#  Constraints:
#  
#  1 <= k <= arr.length
#  1 <= arr.length <= 104
#  arr is sorted in ascending order.
#  -104 <= arr[i], x <= 104
#  
#  

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:

        start = 0
        end = len(arr) - k

        while start < end:
            mid = start + (end - start) // 2

            left = x - arr[mid]
            right = arr[mid + k] - x

            if left <= right:
                end = mid
            else:
                start = mid + 1

        return arr[start: start + k]
    
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        
        start = 0
        end = len(arr) - 1

        while end - start + 1 > k:
            if x - arr[start] <= arr[end] - x:
                end -= 1
            else:
                start += 1

        return arr[start: end + 1]
