#  Tag: Array, String, Binary Search, Sliding Window, Prefix Sum
#  Time: O(N + Q)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given a binary string s and an integer k.
#  You are also given a 2D integer array queries, where queries[i] = [li, ri].
#  A binary string satisfies the k-constraint if either of the following conditions holds:
#  
#  The number of 0's in the string is at most k.
#  The number of 1's in the string is at most k.
#  
#  Return an integer array answer, where answer[i] is the number of substrings of s[li..ri] that satisfy the k-constraint.
#   
#  Example 1:
#  
#  Input: s = "0001111", k = 2, queries = [[0,6]]
#  Output: [26]
#  Explanation:
#  For the query [0, 6], all substrings of s[0..6] = "0001111" satisfy the k-constraint except for the substrings s[0..5] = "000111" and s[0..6] = "0001111".
#  
#  Example 2:
#  
#  Input: s = "010101", k = 1, queries = [[0,5],[1,4],[2,3]]
#  Output: [15,9,3]
#  Explanation:
#  The substrings of s with a length greater than 3 do not satisfy the k-constraint.
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 105
#  s[i] is either '0' or '1'.
#  1 <= k <= s.length
#  1 <= queries.length <= 105
#  queries[i] == [li, ri]
#  0 <= li <= ri < s.length
#  All queries are distinct.
#  
#  

class Solution:
    def countKConstraintSubstrings(self, s: str, k: int, queries: List[List[int]]) -> List[int]:
        n = len(s)
        counter = defaultdict(int)
        left = [0 for i in range(n + 1)]
        right = [0 for i in range(n)]
        i = 0
        for j in range(len(s)):
            counter[s[j]] += 1
            while counter['0'] > k and counter['1'] > k:
                counter[s[i]] -= 1
                if counter[s[i]] == 0:
                    del counter[s[i]]
                i += 1
            left[j + 1] = j - i + 1

        j = n - 1
        counter = defaultdict(int)
        for i in range(n - 1, -1, -1):
            counter[s[i]] += 1
            while counter['0'] > k and counter['1'] > k:
                counter[s[j]] -= 1
                if counter[s[j]] == 0:
                    del counter[s[j]]
                j -= 1

            right[i] = j

        for i in range(n):
            left[i + 1] += left[i]

        res = []
        for l, r in queries:
            mid = min(r, right[l])
            length = mid - l + 1
            cur = length * (length + 1) // 2
            cur += left[r + 1] - left[mid + 1]
            res.append(cur)

        return res