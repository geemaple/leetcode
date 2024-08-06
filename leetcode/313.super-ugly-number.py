#  Tag: Array, Math, Dynamic Programming
#  Time: O(NlogK)
#  Space: O(N+K)
#  Ref: -
#  Note: K-Linked-List(dup)

#  A super ugly number is a positive integer whose prime factors are in the array primes.
#  Given an integer n and an array of integers primes, return the nth super ugly number.
#  The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
#   
#  Example 1:
#  
#  Input: n = 12, primes = [2,7,13,19]
#  Output: 32
#  Explanation: [1,2,4,7,8,13,14,16,19,26,28,32] is the sequence of the first 12 super ugly numbers given primes = [2,7,13,19].
#  
#  Example 2:
#  
#  Input: n = 1, primes = [2,3,5]
#  Output: 1
#  Explanation: 1 has no prime factors, therefore all of its prime factors are in the array primes = [2,3,5].
#  
#   
#  Constraints:
#  
#  1 <= n <= 105
#  1 <= primes.length <= 100
#  2 <= primes[i] <= 1000
#  primes[i] is guaranteed to be a prime number.
#  All the values of primes are unique and sorted in ascending order.
#  
#  

class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        k = len(primes)
        dp = [1 for i in range(n)]
        nth = [0 for i in range(k)]
        candidates = [x for x in primes]

        for i in range(1, n):
            dp[i] = min(candidates)

            for j in range(k):
                if dp[i] == candidates[j]:
                    nth[j] += 1
                    candidates[j] = primes[j] * dp[nth[j]]
        
        return dp[-1]

class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        k = len(primes)
        dp = [1 for i in range(n)]
        nth = [0 for i in range(k)]
        heap = []

        for i in range(k):
            heapq.heappush(heap, (primes[i], i))

        for i in range(1, n):
            dp[i] = heap[0][0]
            while len(heap) > 0 and dp[i] == heap[0][0]:
                _, j = heapq.heappop(heap)
                nth[j] += 1
                next_val = primes[j] * dp[nth[j]]
                heapq.heappush(heap, (next_val, j))
        
        return dp[-1]

import heapq
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        ugly_numbers = [1]
        heap = []
        
        for prime in primes:
            heapq.heappush(heap, (prime, prime, 0))  # (value, prime, index)
        
        while len(ugly_numbers) < n:
            val, prime, index = heapq.heappop(heap)
            if val > ugly_numbers[-1]:
                ugly_numbers.append(val)

            next_val = prime * ugly_numbers[index + 1]
            heapq.heappush(heap, (next_val, prime, index + 1))
        
        return ugly_numbers[-1]
    
import heapq
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        k = len(primes)
        heap = [(1, 0)]
        res = 1
        for i in range(n):
            res, idx = heapq.heappop(heap)
            for j in range(idx, k):
                heapq.heappush(heap, (res * primes[j], j))
            
        return res
