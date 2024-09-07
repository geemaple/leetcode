#  Tag: Divide and Conquer, Bit Manipulation
#  Time: O(1)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Write a function that takes the binary representation of a positive integer and returns the number of set bits it has (also known as the Hamming weight).
#   
#  Example 1:
#  
#  Input: n = 11
#  Output: 3
#  Explanation:
#  The input binary string 1011 has a total of three set bits.
#  
#  Example 2:
#  
#  Input: n = 128
#  Output: 1
#  Explanation:
#  The input binary string 10000000 has a total of one set bit.
#  
#  Example 3:
#  
#  Input: n = 2147483645
#  Output: 30
#  Explanation:
#  The input binary string 1111111111111111111111111111101 has a total of thirty set bits.
#  
#   
#  Constraints:
#  
#  1 <= n <= 231 - 1
#  
#   
#  Follow up: If this function is called many times, how would you optimize it?

class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        while (n > 0):
            res += n & 1
            n = n >> 1

        return res

class Solution:
    def hammingWeight(self, n: int) -> int:
        res = 0
        while (n > 0):
            res += 1
            n = n & (n - 1)

        return res