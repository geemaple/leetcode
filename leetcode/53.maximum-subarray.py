class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # suppose sumTo[i] = a[0] + a[1] + ... [i - 1], sumTo(0) = 0
        # the subarray a[i:j] = sumTo[j] - sumTo[i]

        largest = float('-inf')
        smallest = 0
        sumTo = 0

        for num in nums:
            sumTo += num
            largest = max(largest, sumTo - smallest)
            smallest = min(smallest, sumTo)

        return largest