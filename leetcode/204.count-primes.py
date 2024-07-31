#  Tag: Array, Math, Enumeration, Number Theory
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an integer n, return the number of prime numbers that are strictly less than n.
#   
#  Example 1:
#  
#  Input: n = 10
#  Output: 4
#  Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
#  
#  Example 2:
#  
#  Input: n = 0
#  Output: 0
#  
#  Example 3:
#  
#  Input: n = 1
#  Output: 0
#  
#   
#  Constraints:
#  
#  0 <= n <= 5 * 106
#  
#  

class Solution:
    def countPrimes(self, n: int) -> int:
        
        if n <= 2:
            return 0

        prime = [True for i in range(n)]
        count = n - 2 # 去掉0和1

        for i in range(2, int(n ** 0.5) + 1):
            if prime[i]:
                for j in range(i * i, n, i): 
                    if prime[j]:
                        prime[j] = False
                        count -= 1
        return count
    
class Solution:
    def countPrimes(self, n: int) -> int:
        
        if n <= 2:
            return 0

        prime = [True for i in range(n)]
        count = n // 2 - 1 # 去掉偶数 和 1 
        for i in range(3, int(n ** 0.5) + 1, 2):
            if prime[i]:
                for j in range(i * i, n, 2 * i):
                    if prime[j]:
                        prime[j] = False
                        count -= 1

        return count + 1 # 加上2