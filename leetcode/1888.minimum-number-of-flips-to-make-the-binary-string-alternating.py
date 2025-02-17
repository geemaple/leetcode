#  Tag: String, Dynamic Programming, Greedy, Sliding Window
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:
#  
#  Type-1: Remove the character at the start of the string s and append it to the end of the string.
#  Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
#  
#  Return the minimum number of type-2 operations you need to perform such that s becomes alternating.
#  The string is called alternating if no two adjacent characters are equal.
#  
#  For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
#  
#   
#  Example 1:
#  
#  Input: s = "111000"
#  Output: 2
#  Explanation: Use the first operation two times to make s = "100011".
#  Then, use the second operation on the third and sixth elements to make s = "101010".
#  
#  Example 2:
#  
#  Input: s = "010"
#  Output: 0
#  Explanation: The string is already alternating.
#  
#  Example 3:
#  
#  Input: s = "1110"
#  Output: 1
#  Explanation: Use the second operation on the second element to make s = "1010".
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 105
#  s[i] is either '0' or '1'.
#  
#  

class Solution:
    def minFlips(self, s: str) -> int:
        k = len(s)
        s += s
        n = len(s)
        s1 = ""
        s2 = ""
        for i in range(n):
            s1 += '1' if i % 2 == 0 else '0'
            s2 += '1' if i % 2 == 1 else '0'

        res = k
        count1 = 0
        count2 = 0
        for i in range(n):
            if i >= k:
                if s[i - k] != s1[i - k]:
                    count1 -= 1
                if s[i - k] != s2[i - k]:
                    count2 -= 1

            if s[i] != s1[i]:
                count1 += 1
            if s[i] != s2[i]:
                count2 += 1

            if i >= k - 1:
                res = min(res, count1, count2)
     
        return res

class Solution:
    def minFlips(self, s: str) -> int:
        n = len(s)
        counter = [0, 0]
        outer = (n + 1) // 2
        inner = n - outer

        res = n
        for i in range(2 * n):
            if i >= n:
                counter[(i - n) & 1] -= int(s[i - n])

            counter[i & 1] += int(s[i % n])

            if i >= n - 1:
                k = (i - n + 1) % 2
                count = min(outer - counter[k] + counter[1 - k], counter[k] + inner - counter[1 - k])
                res = min(res, count)

        return res