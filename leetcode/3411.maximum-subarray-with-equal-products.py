#  Tag: Array, Math, Sliding Window, Enumeration, Number Theory
#  Time: O(N * sqrt(Num))
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given an array of positive integers nums.
#  An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:
#  
#  prod(arr) is the product of all elements of arr.
#  gcd(arr) is the GCD of all elements of arr.
#  lcm(arr) is the LCM of all elements of arr.
#  
#  Return the length of the longest product equivalent subarray of nums.
#   
#  Example 1:
#  
#  Input: nums = [1,2,1,2,1,1,1]
#  Output: 5
#  Explanation: 
#  The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
#  
#  Example 2:
#  
#  Input: nums = [2,3,4,5,6]
#  Output: 3
#  Explanation: 
#  The longest product equivalent subarray is [3, 4, 5].
#  
#  Example 3:
#  
#  Input: nums = [1,2,3,1,4,5,1]
#  Output: 5
#  
#   
#  Constraints:
#  
#  2 <= nums.length <= 100
#  1 <= nums[i] <= 10
#  
#  

class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        res = 2
        i = 0
        last = {}
        for j in range(n):
            primes = self.getPrimes(nums[j])
            for p in primes:
                next_i = last[p] + 1 if p in last else 0
                i = max(i, next_i)
                last[p] = j
            res = max(res, j - i + 1)

        return res

    def getPrimes(self, x: int) -> list:
        res = []
        d = 2
        while d * d <= x:
            if x % d == 0:
                res.append(d)
                while (x % d == 0):
                    x //= d
            d += 1

        if x > 1:
            res.append(x)
        return res

import math
class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        for i in range(n):
            prod = 1
            gcd = nums[i]
            lcm = nums[i]
            for j in range(i, n):
                prod = prod * nums[j]
                gcd = math.gcd(gcd, nums[j])
                lcm = lcm * nums[j] // math.gcd(lcm, nums[j])

                if prod == lcm * gcd:
                    res = max(res, j - i + 1)
        return res