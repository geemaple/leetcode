#  Tag: Array, Hash Table, Dynamic Programming
#  Time: O(N^2)
#  Space: O(N^2)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/TPkKMcx4zwA

#  A sequence x1, x2, ..., xn is Fibonacci-like if:
#  
#  n >= 3
#  xi + xi+1 == xi+2 for all i + 2 <= n
#  
#  Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
#  A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].
#   
#  Example 1:
#  
#  Input: arr = [1,2,3,4,5,6,7,8]
#  Output: 5
#  Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].
#  Example 2:
#  
#  Input: arr = [1,3,7,11,12,14,18]
#  Output: 3
#  Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].
#   
#  Constraints:
#  
#  3 <= arr.length <= 1000
#  1 <= arr[i] < arr[i + 1] <= 109
#  
#  

class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        table = set(arr)
        res = 0
        for i in range(n):
            for j in range(i + 1, n):
                pre = arr[i]
                cur = arr[j]
                length = 2
                while pre + cur in table:
                    length += 1
                    pre, cur = cur, pre + cur

                res = max(res, length)

        return res if res >= 3 else 0

class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        n = len(arr)
        table = {}
        dp = [[0] * n for i in range(n)] 
        res = 0
        for i in range(n):
            table[arr[i]] = i
            for j in range(i + 1, n):
                pre = arr[j] - arr[i]
                if pre in table and pre < arr[i]:
                    dp[i][j] = dp[table[pre]][i] + 1
                else:
                    dp[i][j] = 2

                res = max(res, dp[i][j])

        return res if res >= 3 else 0