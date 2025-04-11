#  Tag: Array, Queue, Sliding Window, Heap (Priority Queue), Ordered Set, Monotonic Queue
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:
#  
#  Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
#  
#  Return the total number of continuous subarrays.
#  A subarray is a contiguous non-empty sequence of elements within an array.
#   
#  Example 1:
#  
#  Input: nums = [5,4,2,4]
#  Output: 8
#  Explanation: 
#  Continuous subarray of size 1: [5], [4], [2], [4].
#  Continuous subarray of size 2: [5,4], [4,2], [2,4].
#  Continuous subarray of size 3: [4,2,4].
#  There are no subarrys of size 4.
#  Total continuous subarrays = 4 + 3 + 1 = 8.
#  It can be shown that there are no more continuous subarrays.
#  
#   
#  Example 2:
#  
#  Input: nums = [1,2,3]
#  Output: 6
#  Explanation: 
#  Continuous subarray of size 1: [1], [2], [3].
#  Continuous subarray of size 2: [1,2], [2,3].
#  Continuous subarray of size 3: [1,2,3].
#  Total continuous subarrays = 3 + 2 + 1 = 6.
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  1 <= nums[i] <= 109
#  
#  

from collections import deque
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        minq = deque()
        maxq = deque()

        i = 0
        res = 0
        for j in range(n):
            while len(maxq) > 0 and nums[j] > nums[maxq[-1]]:
                maxq.pop()

            maxq.append(j)
            while len(minq) > 0 and nums[j] < nums[minq[-1]]:
                minq.pop()

            minq.append(j)
            while (nums[maxq[0]] - nums[minq[0]]) > 2:
                if i == maxq[0]:
                    maxq.popleft()

                if i == minq[0]:
                    minq.popleft()

                i += 1

            print(i, j)
            res += j - i + 1
        return res

from sortedcontainers import SortedList
class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        i = 0
        res = 0
        win = SortedList()
        for j in range(n):
            win.add(nums[j])
            while win[-1] - win[0] > 2:
                win.remove(nums[i])
                i += 1

            res += j - i + 1

        return res