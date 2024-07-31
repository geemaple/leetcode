#  Tag: Math, String
#  Time: O(logN)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
#  For example:
#  
#  A -> 1
#  B -> 2
#  C -> 3
#  ...
#  Z -> 26
#  AA -> 27
#  AB -> 28 
#  ...
#  
#   
#  Example 1:
#  
#  Input: columnNumber = 1
#  Output: "A"
#  
#  Example 2:
#  
#  Input: columnNumber = 28
#  Output: "AB"
#  
#  Example 3:
#  
#  Input: columnNumber = 701
#  Output: "ZY"
#  
#   
#  Constraints:
#  
#  1 <= columnNumber <= 231 - 1
#  
#  

class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        res = ''
        alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
        while columnNumber > 0:
            columnNumber -= 1
            i = (columnNumber) % 26
            columnNumber = (columnNumber) // 26
            res = alphabet[i] + res
        
        return res