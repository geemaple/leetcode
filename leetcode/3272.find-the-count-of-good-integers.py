#  Tag: Hash Table, Math, Combinatorics, Enumeration
#  Time: O(10**(N/2) * NlogN)
#  Space: O(10**(N/2))
#  Ref: -
#  Note: -
#  Video: https://youtu.be/MspuxMFiZeM

#  You are given two positive integers n and k.
#  An integer x is called k-palindromic if:
#  
#  x is a palindrome.
#  x is divisible by k.
#  
#  An integer is called good if its digits can be rearranged to form a k-palindromic integer. For example, for k = 2, 2020 can be rearranged to form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to form a k-palindromic integer.
#  Return the count of good integers containing n digits.
#  Note that any integer must not have leading zeros, neither before nor after rearrangement. For example, 1010 cannot be rearranged to form 101.
#   
#  Example 1:
#  
#  Input: n = 3, k = 5
#  Output: 27
#  Explanation:
#  Some of the good integers are:
#  
#  551 because it can be rearranged to form 515.
#  525 because it is already k-palindromic.
#  
#  
#  Example 2:
#  
#  Input: n = 1, k = 4
#  Output: 2
#  Explanation:
#  The two good integers are 4 and 8.
#  
#  Example 3:
#  
#  Input: n = 5, k = 6
#  Output: 2468
#  
#   
#  Constraints:
#  
#  1 <= n <= 10
#  1 <= k <= 9
#  
#  

from collections import Counter
class Solution:
    def countGoodIntegers(self, n: int, k: int) -> int:
        
        fac = [1 for i in range(n + 1)]
        for i in range(2, n + 1):
            fac[i] = i * fac[i - 1]

        half = (n + 1) // 2
        res = 0
        seen = set()
        for d in range(10 ** (half - 1), 10 ** half):
            num_str = str(d) + str(d)[::-1][n % 2:]
            
            if int(num_str) % k == 0:
                key = ''.join(sorted(num_str))
                if key not in seen:
                    seen.add(key)
                    count = Counter(num_str)
                    x = (n - count['0']) * fac[n - 1]
                    for i, c in count.items():
                        x //= fac[c]
                    res += x
        return res