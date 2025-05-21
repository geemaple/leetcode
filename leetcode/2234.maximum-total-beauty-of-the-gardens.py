#  Tag: Array, Two Pointers, Binary Search, Greedy, Sorting, Enumeration, Prefix Sum
#  Time: O(NlogN + T)
#  Space: O(1)
#  Ref: -
#  Note: -

#  Alice is a caretaker of n gardens and she wants to plant flowers to maximize the total beauty of all her gardens.
#  You are given a 0-indexed integer array flowers of size n, where flowers[i] is the number of flowers already planted in the ith garden. Flowers that are already planted cannot be removed. You are then given another integer newFlowers, which is the maximum number of flowers that Alice can additionally plant. You are also given the integers target, full, and partial.
#  A garden is considered complete if it has at least target flowers. The total beauty of the gardens is then determined as the sum of the following:
#  
#  The number of complete gardens multiplied by full.
#  The minimum number of flowers in any of the incomplete gardens multiplied by partial. If there are no incomplete gardens, then this value will be 0.
#  
#  Return the maximum total beauty that Alice can obtain after planting at most newFlowers flowers.
#   
#  Example 1:
#  
#  Input: flowers = [1,3,1,1], newFlowers = 7, target = 6, full = 12, partial = 1
#  Output: 14
#  Explanation: Alice can plant
#  - 2 flowers in the 0th garden
#  - 3 flowers in the 1st garden
#  - 1 flower in the 2nd garden
#  - 1 flower in the 3rd garden
#  The gardens will then be [3,6,2,2]. She planted a total of 2 + 3 + 1 + 1 = 7 flowers.
#  There is 1 garden that is complete.
#  The minimum number of flowers in the incomplete gardens is 2.
#  Thus, the total beauty is 1 * 12 + 2 * 1 = 12 + 2 = 14.
#  No other way of planting flowers can obtain a total beauty higher than 14.
#  
#  Example 2:
#  
#  Input: flowers = [2,4,5,3], newFlowers = 10, target = 5, full = 2, partial = 6
#  Output: 30
#  Explanation: Alice can plant
#  - 3 flowers in the 0th garden
#  - 0 flowers in the 1st garden
#  - 0 flowers in the 2nd garden
#  - 2 flowers in the 3rd garden
#  The gardens will then be [5,4,5,5]. She planted a total of 3 + 0 + 0 + 2 = 5 flowers.
#  There are 3 gardens that are complete.
#  The minimum number of flowers in the incomplete gardens is 4.
#  Thus, the total beauty is 3 * 2 + 4 * 6 = 6 + 24 = 30.
#  No other way of planting flowers can obtain a total beauty higher than 30.
#  Note that Alice could make all the gardens complete but in this case, she would obtain a lower total beauty.
#  
#   
#  Constraints:
#  
#  1 <= flowers.length <= 105
#  1 <= flowers[i], target <= 105
#  1 <= newFlowers <= 1010
#  1 <= full, partial <= 105
#  
#  

class Solution:
    def maximumBeauty(self, flowers: List[int], newFlowers: int, target: int, full: int, partial: int) -> int:
        n = len(flowers)
        flowers.sort()
        r = n - 1
        while r >= 0 and flowers[r] + newFlowers >= target:
            newFlowers -= max(0, target - flowers[r])
            r -= 1
        
        if r == -1:
            res = n * full
            if flowers[0] < target:
                res = max(res, (n - 1) * full + (target - 1) * partial)
            return res

        l = 0
        height = flowers[0]
        area = 0
        res = 0
        while height < target:
            while l <= r and flowers[l] <= height:
                area += flowers[l]
                l += 1

            needed = height * l - area
            if newFlowers >= needed:
                res = max(res, (n - 1 - r) * full + height * partial)
                height += 1
            elif r + 1 < n:
                newFlowers += max(0, target - flowers[r + 1])
                r += 1
            else:
                break

        return res