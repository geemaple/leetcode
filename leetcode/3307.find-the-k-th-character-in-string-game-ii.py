#  Tag: Math, Bit Manipulation, Recursion
#  Time: O(LogK)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/ICgn_GgySd4

#  Alice and Bob are playing a game. Initially, Alice has a string word = "a".
#  You are given a positive integer k. You are also given an integer array operations, where operations[i] represents the type of the ith operation.
#  Now Bob will ask Alice to perform all operations in sequence:
#  
#  If operations[i] == 0, append a copy of word to itself.
#  If operations[i] == 1, generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word. For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
#  
#  Return the value of the kth character in word after performing all the operations.
#  Note that the character 'z' can be changed to 'a' in the second type of operation.
#   
#  Example 1:
#  
#  Input: k = 5, operations = [0,0,0]
#  Output: "a"
#  Explanation:
#  Initially, word == "a". Alice performs the three operations as follows:
#  
#  Appends "a" to "a", word becomes "aa".
#  Appends "aa" to "aa", word becomes "aaaa".
#  Appends "aaaa" to "aaaa", word becomes "aaaaaaaa".
#  
#  
#  Example 2:
#  
#  Input: k = 10, operations = [0,1,0,1]
#  Output: "b"
#  Explanation:
#  Initially, word == "a". Alice performs the four operations as follows:
#  
#  Appends "a" to "a", word becomes "aa".
#  Appends "bb" to "aa", word becomes "aabb".
#  Appends "aabb" to "aabb", word becomes "aabbaabb".
#  Appends "bbccbbcc" to "aabbaabb", word becomes "aabbaabbbbccbbcc".
#  
#  
#   
#  Constraints:
#  
#  1 <= k <= 1014
#  1 <= operations.length <= 100
#  operations[i] is either 0 or 1.
#  The input is generated such that word has at least k characters after all operations.
#  
#  

from math import log2, floor
class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        shift = 0
        for i in range(floor(log2(k)), -1, -1):
            if (k > (1 << i)):
                k -= (1 << i)
                shift += operations[i]

        return chr(ord('a') + shift % 26)

class Solution:
    def kthCharacter(self, k: int, operations: List[int]) -> str:
        return self.getChar(len(operations), operations, k - 1)        

    def getChar(self, l: int, operations: list, k: int) -> str:
        if l == 0:
            return 'a'

        half = 1 << (l - 1)
        if k < half:
            return self.getChar(l - 1, operations, k)
        else:
            char = self.getChar(l - 1, operations, k - half)
            if operations[l - 1] == 1:
                return chr((ord(char) - ord('a') + 1) % 26 + ord('a'))
            else:
                return char