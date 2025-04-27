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
        l = 0
        r = len(arr) - k

        while l < r:
            mid = l + (r - l) // 2
            if arr[mid + k] - x >= x - arr[mid]:
                r = mid
            else:
                l = mid + 1

        return arr[l: l + k]

    
class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        l = 0
        r = len(arr) - 1

        while r - l + 1 > k:
            if arr[r] - x >= x - arr[l]:
                r -= 1
            else:
                l += 1 

        return arr[l: r + 1]
