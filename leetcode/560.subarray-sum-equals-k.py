# O(N)
# suppose sumTo[i] = a[0] + a[1] + ... [i - 1], sumTo(0) = 0
# the subarray a[i:j] = sumTo[j] - sumTo[i]
class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        count_map = {k: 1}
        count = 0
        prefix_sum = 0
        
        for i in range(len(nums)):
            prefix_sum += nums[i]
            count += count_map.get(prefix_sum, 0)
            count_map[prefix_sum + k] = count_map.get(prefix_sum + k, 0) + 1
                
        return count


# ✘ Time Limit Exceeded
# O(N^2)
# suppose sumTo[i] = a[0] + a[1] + ... [i - 1], sumTo(0) = 0
# the subarray a[i:j] = sumTo[j] - sumTo[i]
# class Solution(object):
#     def subarraySum(self, nums, k):
#         """
#         :type nums: List[int]
#         :type k: int
#         :rtype: int
#         """
#         sumTo = [0]
#         total = 0
#         count = 0

#         for num in nums:

#             total += num

#             for pre in sumTo:
#                 if total - pre == k:
#                     count += 1

#             sumTo.append(total)

#         return count