#  Tag: Hash Table, String, Backtracking, Counting
#  Time: O(N!)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/Q2z9GbjkWmo

#  You have n  tiles, where each tile has one letter tiles[i] printed on it.
#  Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
#   
#  Example 1:
#  
#  Input: tiles = "AAB"
#  Output: 8
#  Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
#  
#  Example 2:
#  
#  Input: tiles = "AAABBC"
#  Output: 188
#  
#  Example 3:
#  
#  Input: tiles = "V"
#  Output: 1
#  
#   
#  Constraints:
#  
#  1 <= tiles.length <= 7
#  tiles consists of uppercase English letters.
#  
#  

class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        n = len(tiles)
        used = [False for i in range(n)]
        res = []

        self.helper(sorted(tiles), used, res, "")
        return len(res)

    def helper(self, tiles: list, used: list, res: list, tmp: str):
        for i in range(len(tiles)):
            if used[i]:
                continue

            if i == 0 or tiles[i] != tiles[i - 1] or used[i - 1]:
                used[i] = True
                sub = tmp + tiles[i]
                res.append(sub)
                self.helper(tiles, used, res, sub)
                used[i] = False

from collections import Counter
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        self.res = 0 
        freq = Counter(tiles)
        self.backtrack(freq)
        return self.res

    def backtrack(self, freq):
        for ch in freq:
            if freq[ch] > 0:
                self.res += 1
                freq[ch] -= 1
                self.backtrack(freq)
                freq[ch] += 1