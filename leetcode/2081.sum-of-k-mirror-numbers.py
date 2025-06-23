#  Tag: Math, Enumeration
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/GlW7BUi1WRk

#  A k-mirror number is a positive integer without leading zeros that reads the same both forward and backward in base-10 as well as in base-k.
#  
#  For example, 9 is a 2-mirror number. The representation of 9 in base-10 and base-2 are 9 and 1001 respectively, which read the same both forward and backward.
#  On the contrary, 4 is not a 2-mirror number. The representation of 4 in base-2 is 100, which does not read the same both forward and backward.
#  
#  Given the base k and the number n, return the sum of the n smallest k-mirror numbers.
#   
#  Example 1:
#  
#  Input: k = 2, n = 5
#  Output: 25
#  Explanation:
#  The 5 smallest 2-mirror numbers and their representations in base-2 are listed as follows:
#    base-10    base-2
#      1          1
#      3          11
#      5          101
#      7          111
#      9          1001
#  Their sum = 1 + 3 + 5 + 7 + 9 = 25. 
#  
#  Example 2:
#  
#  Input: k = 3, n = 7
#  Output: 499
#  Explanation:
#  The 7 smallest 3-mirror numbers are and their representations in base-3 are listed as follows:
#    base-10    base-3
#      1          1
#      2          2
#      4          11
#      8          22
#      121        11111
#      151        12121
#      212        21212
#  Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
#  
#  Example 3:
#  
#  Input: k = 7, n = 17
#  Output: 20379000
#  Explanation: The 17 smallest 7-mirror numbers are:
#  1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064, 6597956, 6958596
#  
#   
#  Constraints:
#  
#  2 <= k <= 9
#  1 <= n <= 30
#  
#  

class Solution:
    def kMirror(self, k: int, n: int) -> int:
        res = 0
        l = 1
        pre = [0]
        cur = [0]
        for d in range(1, 10):
            if n == 0:
                break

            cur.append(d)
            if self.testK(d, k):
                res += d
                n -= 1

        return res + self.find(2, 10, pre, cur, k, n)

    def testK(self, num: int, base: int) -> bool:
        mul = 1
        while mul * base <= num:
            mul *= base

        while num > 0:
            if num // mul != num % base:
                return False

            num = (num - (num // mul) * mul - num % base) // base 
            mul //= base * base

        return True

    def find(self, l: int, first_mul, pre: list, cur: list, k: int, n: int) -> int:
        tmp = []
        res = 0
        for i in range(10):
            for j in range(len(pre)):
                if n == 0:
                    break

                tmp.append(first_mul * i + pre[j] * 10 + i)
                if (i != 0 and self.testK(tmp[-1], k)):
                    res += tmp[-1]
                    n -= 1
                    
        return res + (0 if n == 0 else self.find(l + 1, first_mul * 10, cur, tmp, k, n))

class Solution:
    def kMirror(self, k: int, n: int) -> int:
        res = []
        l = 1
        while len(res) < n:
            tmp = [''] * l
            self.find(l, 0, tmp, res, k, n)
            l += 1

        return sum(res)

    def testK(self, num: int, k: int) -> bool:
        digits = []
        while num > 0:
            digits.append(num % k)
            num = num // k

        l = 0
        r = len(digits) - 1
        while l < r and digits[l] == digits[r]:
            l += 1
            r -= 1
        return l >= r

    def find(self, l: int, i: int, tmp: list, res: list, k: int, n: int):
        if len(res) == n:
            return

        if i > l - 1 - i:
            num = int(''.join(tmp))
            if self.testK(num, k):
                res.append(num)
            return

        for d in range(10):
            if i == 0 and d == 0:
                continue

            tmp[i] = tmp[l - 1 - i] = str(d)
            self.find(l, i + 1, tmp, res, k, n)