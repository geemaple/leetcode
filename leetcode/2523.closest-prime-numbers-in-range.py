#  Tag: Math, Number Theory
#  Time: O(NloglogN)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/IQw7Fmb3kUc

#  Given two positive integers left and right, find the two integers num1 and num2 such that:
#  
#  left <= num1 < num2 <= right .
#  Both num1 and num2 are prime numbers.
#  num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
#  
#  Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].
#   
#  Example 1:
#  
#  Input: left = 10, right = 19
#  Output: [11,13]
#  Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
#  The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
#  Since 11 is smaller than 17, we return the first pair.
#  
#  Example 2:
#  
#  Input: left = 4, right = 6
#  Output: [-1,-1]
#  Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
#  
#   
#  Constraints:
#  
#  1 <= left <= right <= 106
#  
#   
#  
#  

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        primes = self.getPrimes(right + 1)
        cur = None  
        pre = None
        res = [-1, -1]

        for x in range(left, right + 1):
            if primes[x]:
                pre = cur
                cur = x
       
            if pre is not None:
                if res[0] == - 1 or cur - pre < res[1] - res[0]:
                    res = [pre, cur]

        return res if res else [-1, -1]
            
    def getPrimes(self, n):
        primes = [True for i in range(n)]
        primes[0] = primes[1] = False

        for i in range(2, int(n ** 0.5) + 1):
            if primes[i]:
                for j in range(i * i, n, i):
                    primes[j] = False

        return primes