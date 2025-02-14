#  Tag: Hash Table, String, Bit Manipulation, Rolling Hash, Hash Function
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.
#   
#  Example 1:
#  
#  Input: s = "00110110", k = 2
#  Output: true
#  Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
#  
#  Example 2:
#  
#  Input: s = "0110", k = 1
#  Output: true
#  Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
#  
#  Example 3:
#  
#  Input: s = "0110", k = 2
#  Output: false
#  Explanation: The binary code "00" is of length 2 and does not exist in the array.
#  
#   
#  Constraints:
#  
#  1 <= s.length <= 5 * 105
#  s[i] is either '0' or '1'.
#  1 <= k <= 20
#  
#  

class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        target = 2 ** k
        visited = set()
        n = len(s)
        for i in range(n - k + 1):
            visited.add(s[i: i + k])

        return len(visited) == target
    
class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        target = 1 << k
        mask = target - 1
        visited = [False for i in range(target)]
        find = 0
        hashing = 0

        for j in range(len(s)):
            hashing = ((hashing << 1) & mask ) | int(s[j])

            if j >= k - 1 and not visited[hashing]:
                visited[hashing] = True
                find += 1

        return find == target