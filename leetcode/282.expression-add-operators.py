#  Tag: Math, String, Backtracking
#  Time: O(2^N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a string num that contains only digits and an integer target, return all possibilities to insert the binary operators '+', '-', and/or '*' between the digits of num so that the resultant expression evaluates to the target value.
#  Note that operands in the returned expressions should not contain leading zeros.
#   
#  Example 1:
#  
#  Input: num = "123", target = 6
#  Output: ["1*2*3","1+2+3"]
#  Explanation: Both "1*2*3" and "1+2+3" evaluate to 6.
#  
#  Example 2:
#  
#  Input: num = "232", target = 8
#  Output: ["2*3+2","2+3*2"]
#  Explanation: Both "2*3+2" and "2+3*2" evaluate to 8.
#  
#  Example 3:
#  
#  Input: num = "3456237490", target = 9191
#  Output: []
#  Explanation: There are no expressions that can be created from "3456237490" to evaluate to 9191.
#  
#   
#  Constraints:
#  
#  1 <= num.length <= 10
#  num consists of only digits.
#  -231 <= target <= 231 - 1
#  
#  

class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        res = []
        self.helper(num, 0, 0, 0, target, '', res)
        return res

    def helper(self, num: str, index: int, pre: int, value: int, target: int, ans: str, res: list):
        n = len(num)
        if index == n:
            if value == target:
                res.append(ans)
            return

        cur = 0
        expr = ''
        for i in range(index, n):
            cur = cur * 10 + int(num[i])
            expr += num[i]
            if index == 0:
                self.helper(num, i + 1, cur, cur, target, ans + expr, res)
            else:
                self.helper(num, i + 1, cur, value + cur, target, ans + '+' + expr, res)
                self.helper(num, i + 1, -cur, value - cur, target, ans + '-' + expr, res)
                self.helper(num, i + 1, pre * cur, value - pre + pre * cur, target, ans + '*' + expr, res)

            if num[index] == '0':
                break