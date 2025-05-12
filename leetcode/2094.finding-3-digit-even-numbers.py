#  Tag: Array, Hash Table, Sorting, Enumeration
#  Time: O(1)
#  Space: O(1)
#  Ref: -
#  Note: -
#  Video: https://youtu.be/J_ODVpvGvUg

#  You are given an integer array digits, where each element is a digit. The array may contain duplicates.
#  You need to find all the unique integers that follow the given requirements:
#  
#  The integer consists of the concatenation of three elements from digits in any arbitrary order.
#  The integer does not have leading zeros.
#  The integer is even.
#  
#  For example, if the given digits were [1, 2, 3], integers 132 and 312 follow the requirements.
#  Return a sorted array of the unique integers.
#   
#  Example 1:
#  
#  Input: digits = [2,1,3,0]
#  Output: [102,120,130,132,210,230,302,310,312,320]
#  Explanation: All the possible integers that follow the requirements are in the output array. 
#  Notice that there are no odd integers or integers with leading zeros.
#  
#  Example 2:
#  
#  Input: digits = [2,2,8,8,2]
#  Output: [222,228,282,288,822,828,882]
#  Explanation: The same digit can be used as many times as it appears in digits. 
#  In this example, the digit 8 is used twice each time in 288, 828, and 882. 
#  
#  Example 3:
#  
#  Input: digits = [3,7,5]
#  Output: []
#  Explanation: No even integers can be formed using the given digits.
#  
#   
#  Constraints:
#  
#  3 <= digits.length <= 100
#  0 <= digits[i] <= 9
#  
#  

from collections import Counter
class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        n = len(digits)
        counter = Counter(digits)
        res = []
        self.helper(0, counter, 0, res)
        return res

    def helper(self, i: int, counter: dict, ans: int, res: list):
        if i == 3:
            res.append(ans)
            return

        for d in range(0, 10):
            if (i == 0 and d == 0) or (i == 2 and d % 2 == 1) or counter[d] == 0:
                continue

            counter[d] -= 1
            self.helper(i + 1, counter, ans * 10 + d, res)
            counter[d] += 1