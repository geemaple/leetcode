#  Tag: String
#  Time: O(|S|)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a binary string s and a positive integer n, return true if the binary representation of all the integers in the range [1, n] are substrings of s, or false otherwise.
#  A substring is a contiguous sequence of characters within a string.
#   
#  Example 1:
#  Input: s = "0110", n = 3
#  Output: true
#  Example 2:
#  Input: s = "0110", n = 4
#  Output: false
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 1000
#  s[i] is either '0' or '1'.
#  1 <= n <= 109
#  
#  

import math
class Solution:
    def queryString(self, s: str, n: int) -> bool:
        bits = math.ceil(math.log2(n + 1))
        table = set()
        mask = 0
        for k in range(1, bits + 1): # 32 times most
            mask = (mask << 1) + 1
            num = 0
            for i in range(len(s)):
                num = ((num << 1) + int(s[i])) & mask
                if i >= k - 1:
                    if 0 <= num <= n:
                        table.add(num)

        return len(table) == n