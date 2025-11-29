#  Tag: String, Sliding Window, Enumeration
#  Time: O(N * sqrtN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  You are given a binary string s.
#  Return the number of substrings with dominant ones.
#  A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.
#   
#  Example 1:
#  
#  Input: s = "00011"
#  Output: 5
#  Explanation:
#  The substrings with dominant ones are shown in the table below.
#  
#  
#  
#  
#  i
#  j
#  s[i..j]
#  Number of Zeros
#  Number of Ones
#  
#  
#  
#  
#  3
#  3
#  1
#  0
#  1
#  
#  
#  4
#  4
#  1
#  0
#  1
#  
#  
#  2
#  3
#  01
#  1
#  1
#  
#  
#  3
#  4
#  11
#  0
#  2
#  
#  
#  2
#  4
#  011
#  1
#  2
#  
#  
#  
#  Example 2:
#  
#  Input: s = "101101"
#  Output: 16
#  Explanation:
#  The substrings with non-dominant ones are shown in the table below.
#  Since there are 21 substrings total and 5 of them have non-dominant ones, it follows that there are 16 substrings with dominant ones.
#  
#  
#  
#  
#  i
#  j
#  s[i..j]
#  Number of Zeros
#  Number of Ones
#  
#  
#  
#  
#  1
#  1
#  0
#  1
#  0
#  
#  
#  4
#  4
#  0
#  1
#  0
#  
#  
#  1
#  4
#  0110
#  2
#  2
#  
#  
#  0
#  4
#  10110
#  2
#  3
#  
#  
#  1
#  5
#  01101
#  2
#  3
#  
#  
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 4 * 104
#  s consists only of characters '0' and '1'.
#  
#  

class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        z = 0
        res = 0
        while z + z * z <= n:
            counter = [0] * 2
            pos = 0
            pre = res
            i = 0
            for j in range(n):
                counter[s[j] == '1'] += 1
                while counter[0] > z:
                    counter[s[i] == '1'] -= 1
                    i += 1

                if (counter[0] == z and counter[1] > 0 and counter[1] >= z * z):
                    pos = max(pos, i)
                    while pos < j and s[pos] == '1':
                        pos += 1

                    res += 1 + min(pos - i, counter[1] - z * z) # count j as right fix point

            if res == pre:
                break

            z += 1
        return res