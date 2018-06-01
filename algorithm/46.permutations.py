class Solution(object):
    def permute(self, nums):
        """
            :type nums: List[int]
            :rtype: List[List[int]]
            """
        results = []
        tmp = []
        visted = set()

        self.helper(nums, visted, tmp, results)

        return results

    def helper(self, nums, visted, tmp, results):
        if len(tmp) == len(nums):
            results.append(list(tmp))
            return

        for num in nums:
            
            if num in visted:
                continue
            
            visted.add(num)

            tmp.append(num)
            self.helper(nums, visted, tmp, results)
            tmp.pop()

            visted.remove(num)

