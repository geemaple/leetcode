#  Tag: String, Sliding Window, Enumeration, Prefix Sum
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/cAP-Qe1DduI

#  You are given a string s and an integer k. Your task is to find the maximum difference between the frequency of two characters, freq[a] - freq[b], in a substring subs of s, such that:
#  
#  subs has a size of at least k.
#  Character a has an odd frequency in subs.
#  Character b has an even frequency in subs.
#  
#  Return the maximum difference.
#  Note that subs can contain more than 2 distinct characters.
#   
#  Example 1:
#  
#  Input: s = "12233", k = 4
#  Output: -1
#  Explanation:
#  For the substring "12233", the frequency of '1' is 1 and the frequency of '3' is 2. The difference is 1 - 2 = -1.
#  
#  Example 2:
#  
#  Input: s = "1122211", k = 3
#  Output: 1
#  Explanation:
#  For the substring "11222", the frequency of '2' is 3 and the frequency of '1' is 2. The difference is 3 - 2 = 1.
#  
#  Example 3:
#  
#  Input: s = "110", k = 3
#  Output: -1
#  
#   
#  Constraints:
#  
#  3 <= s.length <= 3 * 104
#  s consists only of digits '0' to '4'.
#  The input is generated that at least one substring has a character with an even frequency and a character with an odd frequency.
#  1 <= k <= s.length
#  
#  

class Solution:
    def maxDifference(self, s: str, k: int) -> int:
        res = float('-inf')
        for a in '01234':
            for b in '01234':
                if a != b:
                    res = max(res, self.find(a, b, s, k))
        return res

    def find(self, a: str, b: str, s: str, k:int) -> int:
        n = len(s)
        minDiff = [[float('inf')] * 2 for _ in range(2)]
        res = float('-inf')
        l = 0
        count_a = count_b = 0
        pre_a = pre_b = 0
        for r in range(n):
            count_a += s[r] == a
            count_b += s[r] == b

            while r - l + 1 >= k and count_b - pre_b >= 2:
                i = pre_a % 2
                j = pre_b % 2
                minDiff[i][j] = min(minDiff[i][j], pre_a - pre_b)
                pre_a += s[l] == a
                pre_b += s[l] == b
                l += 1
                
            i = count_a % 2
            j = count_b % 2
            if minDiff[i ^ 1][j] != float('inf'):
                res = max(res, count_a - count_b - minDiff[i ^ 1][j])

        return res


