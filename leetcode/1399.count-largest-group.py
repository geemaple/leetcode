#  Tag: Hash Table, Math
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/97dMvjUWxt8

#  You are given an integer n.
#  Each number from 1 to n is grouped according to the sum of its digits.
#  Return the number of groups that have the largest size.
#   
#  Example 1:
#  
#  Input: n = 13
#  Output: 4
#  Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
#  [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
#  There are 4 groups with largest size.
#  
#  Example 2:
#  
#  Input: n = 2
#  Output: 2
#  Explanation: There are 2 groups [1], [2] of size 1.
#  
#   
#  Constraints:
#  
#  1 <= n <= 104
#  
#  

from collections import defaultdict
class Solution:
    def countLargestGroup(self, n: int) -> int:
        counter = defaultdict(int)
        res = 0
        for i in range(1, n + 1):
            x = i
            count = 0
            while x > 0:
                count += x % 10
                x = x // 10

            counter[count] += 1
            res = max(res, counter[count])
  
        return len([x for x in counter if counter[x] == res])
