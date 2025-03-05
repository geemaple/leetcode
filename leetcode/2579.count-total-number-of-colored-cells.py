#  Tag: Math
#  Time: O(1)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/k9bLnrFUV9E

#  There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:
#  
#  At the first minute, color any arbitrary unit cell blue.
#  Every minute thereafter, color blue every uncolored cell that touches a blue cell.
#  
#  Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.
#  
#  Return the number of colored cells at the end of n minutes.
#   
#  Example 1:
#  
#  Input: n = 1
#  Output: 1
#  Explanation: After 1 minute, there is only 1 blue cell, so we return 1.
#  
#  Example 2:
#  
#  Input: n = 2
#  Output: 5
#  Explanation: After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5. 
#  
#   
#  Constraints:
#  
#  1 <= n <= 105
#  
#  

class Solution:
    def coloredCells(self, n: int) -> int:
        return 2 * n - 1 + 2 *  (n - 1) * (n - 1)

class Solution:
    def coloredCells(self, n: int) -> int:

        x = 2 * n - 1
        y = 0
        for i in range(1, x, 2):
            y += i * 2

        return x + y