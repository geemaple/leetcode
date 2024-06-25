#  Tag: String
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: Simulation

#  Given a string（Given in the way of char array）, a right offset and a left offset, move the string cyclically according to the given offset and save it in a new result set for return.
#  （Left offest represents the offset of a string to the left,right offest represents the offset of a string to the right,the total offset is calculated from the left offset and the right offset, split two strings at the total offset and swap positions.）
#  
#  **Example 1:**
#  ```
#  Input：str ="abcdefg", left = 3, right = 1
#  Output："cdefgab"
#  Explanation：The left offset is 3, the right offset is 1, and the total offset is left 2. Therefore, the original string moves to the left and becomes "cdefg"+ "ab".
#  ```
#  
#  **Example 2:**
#  ```
#  Input：str="abcdefg", left = 0, right = 0
#  Output："abcdefg"
#  Explanation：The left offset is 0, the right offset is 0, and the total offset is 0. So the string remains unchanged.
#  ```
#  
#  
#  **Example 3:**
#  ```
#  Input：str = "abcdefg",left = 1, right = 2
#  Output："gabcdef"
#  Explanation：The left offset is 1, the right offset is 2, and the total offset is right 1. Therefore, the original string moves to the left and becomes "g" + "abcdef".
#  ```
#  
#  

class Solution:
    """
    @param str: An array of char
    @param left: a left offset
    @param right: a right offset
    @return: return a rotate string
    """
    def rotate_string2(self, str: str, left: int, right: int) -> str:
        # write your code here
        length = len(str)
        pos = (left - right) % length
        pos = pos if pos > 0 else length + pos
        return str[pos:] + str[:pos] # [left: right)