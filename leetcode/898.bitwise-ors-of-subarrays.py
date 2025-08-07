#  Tag: Array, Dynamic Programming, Bit Manipulation
#  Time: O(N^2)
#  Space: O(N^2)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/GkS3h6CU7Pk

#  Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
#  The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
#  A subarray is a contiguous non-empty sequence of elements within an array.
#   
#  Example 1:
#  
#  Input: arr = [0]
#  Output: 1
#  Explanation: There is only one possible result: 0.
#  
#  Example 2:
#  
#  Input: arr = [1,1,2]
#  Output: 3
#  Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
#  These yield the results 1, 1, 2, 1, 3, 3.
#  There are 3 unique values, so the answer is 3.
#  
#  Example 3:
#  
#  Input: arr = [1,2,4]
#  Output: 6
#  Explanation: The possible results are 1, 2, 3, 4, 6, and 7.
#  
#   
#  Constraints:
#  
#  1 <= arr.length <= 5 * 104
#  0 <= arr[i] <= 109
#  
#  

class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        res = set()
        cur = set()
        for i in arr:
            tmp = set()
            for j in cur:
                tmp.add(i | j)
            cur = tmp | {i}
            res |= cur

        return len(res)

class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        n = len(arr)
        res = []
        start = 0
        end = 0
        for i in range(n):
            res.append(arr[i])
            for j in range(start, end):
                if (res[-1] < (res[j] | arr[i])):
                    res.append(res[j] | arr[i])

            start = end
            end = len(res)

        return len(set(res))