# f[i] = max(f[i - 1] + nums[i], nums[i])
class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if nums is None or len(nums) == 0:
            return 0
        
        table = [0 for _ in range(len(nums))]
        largest = nums[0]
        table[0] = nums[0]
        
        for i in range(1, len(nums)):
            table[i] = max(table[i - 1] + nums[i], nums[i])
            largest = max(largest, table[i])

        return largest

# prefix-sum
class Solution2(object):
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