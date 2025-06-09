#  Tag: Trie
#  Time: O((logN) ^ 2)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/un_lgww-7zo

#  Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].
#   
#  Example 1:
#  
#  Input: n = 13, k = 2
#  Output: 10
#  Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
#  
#  Example 2:
#  
#  Input: n = 1, k = 1
#  Output: 1
#  
#   
#  Constraints:
#  
#  1 <= k <= n <= 109
#  
#  

class Solution:
    def findKthNumber(self, n: int, k: int) -> int:        
        prefix = 1
        k -= 1
        
        while k > 0:
            count = self.count_prefix(prefix, n)
            if count <= k:
                prefix += 1
                k -= count
            else:
                prefix *= 10
                k -= 1
        
        return prefix

    def count_prefix(self, prefix: int, n: int) -> int:
        count = 0
        next_prefix = prefix + 1
        while prefix <= n:
            count += min(n + 1, next_prefix) - prefix
            prefix *= 10
            next_prefix *= 10
        return count