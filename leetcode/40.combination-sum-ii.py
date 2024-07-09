#  Tag: Array, Backtracking
#  Time: O(2^N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
#  Each number in candidates may only be used once in the combination.
#  Note: The solution set must not contain duplicate combinations.
#   
#  Example 1:
#  
#  Input: candidates = [10,1,2,7,6,1,5], target = 8
#  Output: 
#  [
#  [1,1,6],
#  [1,2,5],
#  [1,7],
#  [2,6]
#  ]
#  
#  Example 2:
#  
#  Input: candidates = [2,5,2,1,2], target = 5
#  Output: 
#  [
#  [1,2,2],
#  [5]
#  ]
#  
#   
#  Constraints:
#  
#  1 <= candidates.length <= 100
#  1 <= candidates[i] <= 50
#  1 <= target <= 30
#  
#  

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        visited = set()
        res = []
        self.dfs(candidates, target, 0,  visited, [], res)

        return res

    def dfs(self, candidates: List[int], remain: int, start: int, visited: set, tmp: list, res: list):
        if remain == 0:
            res.append(tmp.copy())
            return

        for i in range(start, len(candidates)):
            
            if i > 0 and candidates[i] == candidates[i - 1] and (i - 1) not in visited:
                continue
            
            if i not in visited and remain - candidates[i] >= 0:
                visited.add(i)
                tmp.append(candidates[i])
                self.dfs(candidates, remain - candidates[i], i + 1, visited, tmp, res)
                tmp.pop()
                visited.remove(i)

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []
        self.dfs(candidates, target, 0, [], res)

        return res

    def dfs(self, candidates: List[int], remain: int, start: int, tmp: list, res: list):
        if remain == 0:
            res.append(tmp.copy())
            return

        for i in range(start, len(candidates)):
            
            if i > start and candidates[i] == candidates[i - 1]:
                continue
            
            if remain - candidates[i] >= 0:
                tmp.append(candidates[i])
                self.dfs(candidates, remain - candidates[i], i + 1, tmp, res)
                tmp.pop()