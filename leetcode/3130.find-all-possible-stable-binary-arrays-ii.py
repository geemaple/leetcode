#  Tag: Dynamic Programming, Prefix Sum
#  Time: -
#  Space: -
#  Ref: -
#  Note: -

#  You are given 3 positive integers zero, one, and limit.
#  A binary array arr is called stable if:
#  
#  The number of occurrences of 0 in arr is exactly zero.
#  The number of occurrences of 1 in arr is exactly one.
#  Each subarray of arr with a size greater than limit must contain both 0 and 1.
#  
#  Return the total number of stable binary arrays.
#  Since the answer may be very large, return it modulo 109 + 7.
#   
#  Example 1:
#  
#  Input: zero = 1, one = 1, limit = 2
#  Output: 2
#  Explanation:
#  The two possible stable binary arrays are [1,0] and [0,1].
#  
#  Example 2:
#  
#  Input: zero = 1, one = 2, limit = 1
#  Output: 1
#  Explanation:
#  The only possible stable binary array is [1,0,1].
#  
#  Example 3:
#  
#  Input: zero = 3, one = 3, limit = 2
#  Output: 14
#  Explanation:
#  All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].
#  
#   
#  Constraints:
#  
#  1 <= zero, one, limit <= 1000
#  
#  

class Solution:
    def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
        mod = 10 ** 9 + 7
        L = limit + 1

        dp0 = [[0] * (one + 1) for _ in range(zero + 1)]  # i 0s + j 1s ending with 0
        dp1 = [[0] * (one + 1) for _ in range(zero + 1)]  # i 0s + j 1s ending with 1

        # Base cases: only zeros or only ones => only one string if len <= min(limit, zero/one)
        for i in range(1, min(zero, limit) + 1):
            dp0[i][0] = 1
        for j in range(1, min(one, limit) + 1):
            dp1[0][j] = 1

        # DP iterations
        for i in range(1, zero + 1):
            for j in range(1, one + 1):
                dp0[i][j] = (dp0[i - 1][j] + dp1[i - 1][j] - (dp1[i - L][j] if i >= L else 0)) % mod
                dp1[i][j] = (dp0[i][j - 1] + dp1[i][j - 1] - (dp0[i][j - L] if j >= L else 0)) % mod

        return (dp0[zero][one] + dp1[zero][one]) % mod