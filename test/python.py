from typing import List
class Solution:
    def countPrimes(self, n: int) -> int:
        
        if n <= 2:
            return 0

        prime = [True for i in range(n)]
        count = n // 2 - 1 # 去掉偶数 和 1 
        for i in range(3, int(n ** 0.5) + 1, 2):
            if prime[i]:
                for j in range(i * i, n, 2 * i):  # step = 2倍的i
                    if prime[j]:
                        prime[j] = False
                        count -= 1

        return count + 1 # 加上2


s = Solution()
res = s.countPrimes(13)
print(res)