#  Tag: Array, Hash Table, Math, Two Pointers
#  Time: O(NM)
#  Space: O(N + M)
#  Ref: -
#  Note: -

#  Given two arrays of integers nums1 and nums2, return the number of triplets formed (type 1 and type 2) under the following rules:
#  
#  Type 1: Triplet (i, j, k) if nums1[i]2 == nums2[j] * nums2[k] where 0 <= i < nums1.length and 0 <= j < k < nums2.length.
#  Type 2: Triplet (i, j, k) if nums2[i]2 == nums1[j] * nums1[k] where 0 <= i < nums2.length and 0 <= j < k < nums1.length.
#  
#   
#  Example 1:
#  
#  Input: nums1 = [7,4], nums2 = [5,2,8,9]
#  Output: 1
#  Explanation: Type 1: (1, 1, 2), nums1[1]2 = nums2[1] * nums2[2]. (42 = 2 * 8). 
#  
#  Example 2:
#  
#  Input: nums1 = [1,1], nums2 = [1,1,1]
#  Output: 9
#  Explanation: All Triplets are valid, because 12 = 1 * 1.
#  Type 1: (0,0,1), (0,0,2), (0,1,2), (1,0,1), (1,0,2), (1,1,2).  nums1[i]2 = nums2[j] * nums2[k].
#  Type 2: (0,0,1), (1,0,1), (2,0,1). nums2[i]2 = nums1[j] * nums1[k].
#  
#  Example 3:
#  
#  Input: nums1 = [7,7,8,3], nums2 = [1,2,9,7]
#  Output: 2
#  Explanation: There are 2 valid triplets.
#  Type 1: (3,0,2).  nums1[3]2 = nums2[0] * nums2[2].
#  Type 2: (3,0,1).  nums2[3]2 = nums1[0] * nums1[1].
#  
#   
#  Constraints:
#  
#  1 <= nums1.length, nums2.length <= 1000
#  1 <= nums1[i], nums2[i] <= 105
#  
#  

from collections import Counter
class Solution:
    def numTriplets(self, nums1: List[int], nums2: List[int]) -> int:
        res = 0
        nums1.sort()
        nums2.sort()
        counter1 = Counter(nums1)
        counter2 = Counter(nums2)
        for x in counter1:
            res += self.count(nums2, counter2, x * x) * counter1[x]

        for x in counter2:
            res += self.count(nums1, counter1, x * x) * counter2[x]

        return res

    def count(self, nums: list, counter: dict, target: int) -> int:
        l = 0
        r = len(nums) - 1
        res = 0
        while l < r:
            tmp = nums[l] * nums[r]
            left = counter[nums[l]]
            right = counter[nums[r]]

            if tmp == target:
                if nums[l] == nums[r]:
                    res += left * (left - 1) // 2
                    break
                else:
                    res += left * right
                    l += left
                    r -= right
            elif tmp > target:
                r -= right
            else:
                l += left

        return res