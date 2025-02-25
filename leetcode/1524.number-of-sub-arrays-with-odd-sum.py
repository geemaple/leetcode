#  Tag: Array, Math, Dynamic Programming, Prefix Sum
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/PxvZ0YL7sao

#  Given an array of integers arr, return the number of subarrays with an odd sum.
#  Since the answer can be very large, return it modulo 109 + 7.
#   
#  Example 1:
#  
#  Input: arr = [1,3,5]
#  Output: 4
#  Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
#  All sub-arrays sum are [1,4,9,3,8,5].
#  Odd sums are [1,9,3,5] so the answer is 4.
#  
#  Example 2:
#  
#  Input: arr = [2,4,6]
#  Output: 0
#  Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
#  All sub-arrays sum are [2,6,12,4,10,6].
#  All sub-arrays have even sum and the answer is 0.
#  
#  Example 3:
#  
#  Input: arr = [1,2,3,4,5,6,7]
#  Output: 16
#  
#   
#  Constraints:
#  
#  1 <= arr.length <= 105
#  1 <= arr[i] <= 100
#  
#  

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        module = 10**9 + 7
        n = len(arr)
        prefix = [0]
        for x in arr:
            prefix.append(prefix[-1] + x)

        even = 1
        odd = 0
        res = 0
        for i in range(1, n + 1):
            if (prefix[i] & 1) == 1:
                odd += 1
                res += even
            else:
                even += 1
                res += odd
                
            res = res % module

        return res

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        module = 10**9 + 7
        n = len(arr)
        prefix_sum = 0
        even = 1
        odd = 0
        res = 0
        for i in range(n):
            prefix_sum += arr[i]
            if (prefix_sum & 1) == 1:
                odd += 1
                res += even
            else:
                even += 1
                res += odd

            res = res % module

        return res