class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        results = []
        visted = []
        sorted_candidates = sorted(candidates)
        self.helper(sorted_candidates, visted, results, 0, target)
        return results

    def helper(self, candidates, visted, results, start, target):

        summation = sum(visted)
        if summation == target:
            results.append(list(visted))
        elif summation > target:
            return

        for i in range(start, len(candidates)):
            visted.append(candidates[i])
            self.helper(candidates, visted, results, i, target)
            visted.pop()

