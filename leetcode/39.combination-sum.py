class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        res = []
        ans = []
        candidates.sort()
        self.helper(candidates, 0, target, ans, 0, res)
        
        return res
        
    def helper(self, candidates, start, target, ans, total, res):
        if total == target:
            res.append(list(ans))
            return
            
        for i in range(start, len(candidates)):
            
            number = candidates[i]
            
            if total + number <= target:
                ans.append(number)
                total += number
                
                self.helper(candidates, i, target, ans, total, res)
                
                total -= number
                ans.pop()