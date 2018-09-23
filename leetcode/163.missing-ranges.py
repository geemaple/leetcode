class Solution(object):
    def findMissingRanges(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: List[str]
        """
        newLower = lower - 1
        newUpper = upper + 1
        tmpLow = newLower
        res = []

        for i in range(len(nums)):
            if nums[i] - tmpLow > 1:
                res.append(self.get_range(tmpLow + 1, nums[i] - 1))
            tmpLow = nums[i]

        if newUpper - tmpLow > 1:
            res.append(self.get_range(tmpLow + 1, newUpper - 1))

        return res

    def get_range(self, lower, upper):
        if lower == upper:
            return str(lower)
        else:
            return str(lower) + '->' + str(upper)