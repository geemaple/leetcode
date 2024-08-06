from typing import List
import heapq
class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        k = len(primes)
        dp = [1 for i in range(n)]
        heap = [x for x in primes]
        heapq.heapify(heap)

        for i in range(1, n):
            dp[i] = heapq.heappop(heap)

            tmp = float('inf')
            for j in range(k): 
                tmp = min(tmp, primes[j] * dp[i])

            heapq.heappush(heap, tmp)
        
        print(dp)
        return dp[n - 1]


s = Solution()
res = s.nthSuperUglyNumber(15, [3,5,7,11,19,23,29,41,43,47])
print(res)