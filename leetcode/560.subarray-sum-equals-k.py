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
        count_map = {0: 1}
        result = 0
        total = 0

        for num in nums:
            total += num
            num_to_check = total - k
            result += count_map.get(num_to_check, 0)
            count_map[total] = count_map.get(total, 0) + 1

        return result


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