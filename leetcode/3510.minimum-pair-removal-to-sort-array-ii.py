#  Tag: Array, Hash Table, Linked List, Heap (Priority Queue), Simulation, Doubly-Linked List, Ordered Set
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an array nums, you can perform the following operation any number of times:
#  
#  Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
#  Replace the pair with their sum.
#  
#  Return the minimum number of operations needed to make the array non-decreasing.
#  An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).
#   
#  Example 1:
#  
#  Input: nums = [5,2,3,1]
#  Output: 2
#  Explanation:
#  
#  The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
#  The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
#  
#  The array nums became non-decreasing in two operations.
#  
#  Example 2:
#  
#  Input: nums = [1,2,2]
#  Output: 0
#  Explanation:
#  The array nums is already sorted.
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  -109 <= nums[i] <= 109
#  
#  

import heapq
class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        n = len(nums)
        pre = [i - 1 for i in range(n)]
        after = [i + 1 for i in range(n)]
        merged = [False for i in range(n)]
        after[n - 1] = -1

        heap = []
        bad = 0
        for i in range(1, n):
            if nums[i - 1] > nums[i]:
                bad += 1
            heapq.heappush(heap, (nums[i - 1] + nums[i], i))

        res = 0
        while bad > 0:
            pair_sum, r = heapq.heappop(heap)
            l = pre[r]
            if l == -1 or merged[l] or merged[r] or nums[l] + nums[r] != pair_sum:
                continue

            after[l] = after[r]
            if after[r] != -1:
                pre[after[r]] = l
                
            if nums[l] > nums[r]:
                bad -= 1

            ll = pre[l]
            rr = after[r]
            if ll != -1:
                bad += (nums[ll] > pair_sum) - (nums[ll] > nums[l])
                heapq.heappush(heap, (nums[ll] + pair_sum, l))
            if rr != -1:
                bad += (pair_sum > nums[rr]) - (nums[r] > nums[rr])
                heapq.heappush(heap, (nums[rr] + pair_sum, rr))

            nums[l] = pair_sum
            merged[r] = True
            res += 1

        return res