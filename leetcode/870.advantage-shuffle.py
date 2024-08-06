#  Tag: Array, Two Pointers, Greedy, Sorting
#  Time: O(NlogN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  You are given two integer arrays nums1 and nums2 both of the same length. The advantage of nums1 with respect to nums2 is the number of indices i for which nums1[i] > nums2[i].
#  Return any permutation of nums1 that maximizes its advantage with respect to nums2.
#   
#  Example 1:
#  Input: nums1 = [2,7,11,15], nums2 = [1,10,4,11]
#  Output: [2,11,7,15]
#  Example 2:
#  Input: nums1 = [12,24,8,32], nums2 = [13,25,32,11]
#  Output: [24,32,8,12]
#  
#   
#  Constraints:
#  
#  1 <= nums1.length <= 105
#  nums2.length == nums1.length
#  0 <= nums1[i], nums2[i] <= 109
#  
#  

from collections import deque
class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        n = len(nums1)
        target = sorted([(nums2[i], i) for i in range(n)], reverse=True)
        q = deque(sorted(nums1))

        res = list(nums2)
        for i in range(n):
            val, j = target[i]
            if q[-1] > val:
                res[j] = q.pop()
            else:
                res[j] = q.popleft()

        return res

