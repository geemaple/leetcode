#  Tag: Array, Backtracking
#  Time: O(N!)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
#   
#  Example 1:
#  
#  Input: nums = [1,1,2]
#  Output:
#  [[1,1,2],
#   [1,2,1],
#   [2,1,1]]
#  
#  Example 2:
#  
#  Input: nums = [1,2,3]
#  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 8
#  -10 <= nums[i] <= 10
#  
#  

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        visited = set()
        res = []
        self.dfs(nums, visited, [], res)
        return res
        

    def dfs(self, nums: List[int], visited: set, tmp: list, res: list[list[int]]):

        if len(tmp) == len(nums):
            res.append(tmp.copy())
            return

        for i in range(len(nums)):

            if i > 0 and nums[i] == nums[i - 1] and (i - 1) not in visited:
                continue

            if i not in visited:
                visited.add(i)
                tmp.append(nums[i])
                self.dfs(nums, visited, tmp, res)
                tmp.pop()
                visited.remove(i)
