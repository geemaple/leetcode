from collections import deque
class Solution:    
    def letterCombinations(self, digits: str) -> List[str]:    
        
        if len(digits) == 0:
            return []
        
        digitToLetter = {
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz',
        }
        
        ans = deque()
        ans.append('')
        
        for i in range(len(digits)):
            num = digits[i]
            while len(ans) > 0 and len(ans[0]) == i: 
                prefix = ans.popleft()
                for letter in digitToLetter[num]:
                    ans.append(prefix + letter)
                    
        return list(ans)
                    

class Solution2:

    digitToLetter = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz',
    }

    def letterCombinations(self, digits: str) -> List[str]:    
        
        if digits is None or len(digits) == 0:
            return []
        
        res = []
        tmp = []
        
        self.helper(digits, 0, res, tmp)
        return res
    
    def helper(self, digits: str, start: int, res: List, tmp: List):
        
        if start == len(digits):
            res.append(''.join(tmp))
            return
        
        letters = self.digitToLetter[digits[start]]
        for i in range(len(letters)):

            tmp.append(letters[i])
            self.helper(digits, start + 1, res, tmp)
            tmp.pop()