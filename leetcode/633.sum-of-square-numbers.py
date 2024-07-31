#  Tag: Math, Two Pointers, Binary Search
#  Time: O(N)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
#   
#  Example 1:
#  
#  Input: c = 5
#  Output: true
#  Explanation: 1 * 1 + 2 * 2 = 5
#  
#  Example 2:
#  
#  Input: c = 3
#  Output: false
#  
#   
#  Constraints:
#  
#  0 <= c <= 231 - 1
#  
#  

class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        start = 0
        end = int(math.sqrt(c))

        while start <= end:
            res = start * start + end * end

            if res == c:
                return True

            if res > c:
                end -= 1
            else:
                start += 1

        return False