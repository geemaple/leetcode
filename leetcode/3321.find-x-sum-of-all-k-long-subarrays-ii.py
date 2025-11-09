#  Tag: Array, Hash Table, Sliding Window, Heap (Priority Queue)
#  Time: O(NLogK)
#  Space: O(K)
#  Ref: -
#  Note: -

#  You are given an array nums of n integers and two integers k and x.
#  The x-sum of an array is calculated by the following procedure:
#  
#  Count the occurrences of all elements in the array.
#  Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
#  Calculate the sum of the resulting array.
#  
#  Note that if an array has less than x distinct elements, its x-sum is the sum of the array.
#  Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].
#   
#  Example 1:
#  
#  Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2
#  Output: [6,10,12]
#  Explanation:
#  
#  For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
#  For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
#  For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
#  
#  
#  Example 2:
#  
#  Input: nums = [3,8,7,8,7,5], k = 2, x = 2
#  Output: [11,15,15,15,12]
#  Explanation:
#  Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].
#  
#   
#  Constraints:
#  
#  nums.length == n
#  1 <= n <= 105
#  1 <= nums[i] <= 109
#  1 <= x <= k <= nums.length
#  
#  

from collections import defaultdict
from sortedcontainers import SortedSet
class Solution:
    def findXSum(self, nums: List[int], k: int, x: int) -> List[int]:
        n = len(nums)
        counter = defaultdict(int)
        top = SortedSet()
        bottom = SortedSet()
        ans = 0
        res = []
        for i in range(n):
            count = counter[nums[i]]
            if count > 0:
                pair = (count, nums[i])
                if pair in bottom:
                    bottom.remove(pair)
                else:
                    top.remove(pair)
                    ans -= count * nums[i]

            counter[nums[i]] = count + 1
            top.add((count + 1, nums[i]))
            ans += (count + 1) * nums[i]
            if len(top) > x:
                val, key = top.pop(0)
                ans -= key * val
                bottom.add((val, key))

            if i >= k - 1:
                res.append(ans)

                count = counter[nums[i - k + 1]]
                
                pair = (count, nums[i - k + 1])
                if pair in bottom:
                    bottom.remove(pair)
                else:
                    top.remove(pair)
                    ans -= count * nums[i - k + 1]

                if count > 1:
                    bottom.add((count - 1, nums[i - k + 1]))

                if len(top) < x and len(bottom) > 0:
                    val, key = bottom.pop(-1)
                    ans += val * key
                    top.add((val, key))

                counter[nums[i - k + 1]] -= 1

        return res