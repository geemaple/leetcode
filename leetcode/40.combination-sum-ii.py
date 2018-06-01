class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        results = []
        visted = []
        sorted_candidates = sorted(candidates)
        self.helper(sorted_candidates, 0, visted, results, target)
        return results

    def helper(self, candidates, start, visted, results, target):

        summation = sum(visted)
        if summation == target:
            results.append(list(visted))
        elif summation > target:
            return

        for i in range(start, len(candidates)):

            if i > start and candidates[i] == candidates[i - 1]:
                continue
                
            visted.append(candidates[i])
            self.helper(candidates, i + 1, visted, results, target)
            visted.pop()

