#  Tag: Math, Combinatorics
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/xokW4a6BVrs

#  You are given three integers n, m, k. A good array arr of size n is defined as follows:
#  
#  Each element in arr is in the inclusive range [1, m].
#  Exactly k indices i (where 1 <= i < n) satisfy the condition arr[i - 1] == arr[i].
#  
#  Return the number of good arrays that can be formed.
#  Since the answer may be very large, return it modulo 109 + 7.
#   
#  Example 1:
#  
#  Input: n = 3, m = 2, k = 1
#  Output: 4
#  Explanation:
#  
#  There are 4 good arrays. They are [1, 1, 2], [1, 2, 2], [2, 1, 1] and [2, 2, 1].
#  Hence, the answer is 4.
#  
#  
#  Example 2:
#  
#  Input: n = 4, m = 2, k = 2
#  Output: 6
#  Explanation:
#  
#  The good arrays are [1, 1, 1, 2], [1, 1, 2, 2], [1, 2, 2, 2], [2, 1, 1, 1], [2, 2, 1, 1] and [2, 2, 2, 1].
#  Hence, the answer is 6.
#  
#  
#  Example 3:
#  
#  Input: n = 5, m = 2, k = 0
#  Output: 2
#  Explanation:
#  
#  The good arrays are [1, 2, 1, 2, 1] and [2, 1, 2, 1, 2]. Hence, the answer is 2.
#  
#  
#   
#  Constraints:
#  
#  1 <= n <= 105
#  1 <= m <= 105
#  0 <= k <= n - 1
#  
#  

def power(n: int, p: int, mod: int) -> int:
    res = 1
    while p > 0:
        if p % 2 == 1:
            res = (res * n) % mod
        
        n = (n * n) % mod
        p //= 2

    return res

def factorial(k: int, mod: int) -> tuple:
    fact = [0] * (k + 1)
    invert = [0] * (k + 1)
    fact[0] = 1  # 0! is 1

    for i in range(1, k + 1):
        fact[i] = fact[i - 1] * i % mod

    invert[k] = power(fact[k], mod - 2, mod)
    for i in range(k, 0, -1):
        invert[i - 1] = invert[i] * i % mod

    return fact, invert

mod = 10 ** 9 + 7
fact, invert = factorial(10 ** 5, mod)

def comb(n: int, m: int, mod: int) -> int:
    return fact[n] * invert[m] % mod * invert[n - m] % mod

class Solution:
    def countGoodArrays(self, n: int, m: int, k: int) -> int:
        return m * power(m - 1, n - k - 1, mod) % mod * comb(n - 1, k, mod) % mod