#  Tag: Math, Bit Manipulation, Recursion, Simulation
#  Time: O(logK)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/vZQSipSk2Fk

#  Alice and Bob are playing a game. Initially, Alice has a string word = "a".
#  You are given a positive integer k.
#  Now Bob will ask Alice to perform the following operation forever:
#  
#  Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
#  
#  For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".
#  Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.
#  Note that the character 'z' can be changed to 'a' in the operation.
#   
#  Example 1:
#  
#  Input: k = 5
#  Output: "b"
#  Explanation:
#  Initially, word = "a". We need to do the operation three times:
#  
#  Generated string is "b", word becomes "ab".
#  Generated string is "bc", word becomes "abbc".
#  Generated string is "bccd", word becomes "abbcbccd".
#  
#  
#  Example 2:
#  
#  Input: k = 10
#  Output: "c"
#  
#   
#  Constraints:
#  
#  1 <= k <= 500
#  
#  

class Solution:
    def kthCharacter(self, k: int) -> str:
        word = 'a'
        while len(word) < k:
            tmp = ''
            for i in range(len(word)):
                tmp += chr((ord(word[i]) - ord('a') + 1) % 26 + ord('a'))

            word += tmp
        return word[k - 1]
    
from math import log2, ceil
class Solution:
    def kthCharacter(self, k: int) -> str:
        l = ceil(log2(k))
        return self.getChar(l, k - 1)

    def getChar(self, l: int, k: int) -> str:
        if l == 0:
            return 'a'

        half = 1 << (l - 1)
        if k < half:
            return self.getChar(l - 1, k)
        else:
            return chr(ord(self.getChar(l - 1, k - half)) + 1)
        
class Solution:
    def kthCharacter(self, k: int) -> str:
        return chr(ord('a') + (k - 1).bit_count())