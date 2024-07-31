#  Tag: Array, Backtracking
#  Time: O(N!)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
#   
#  Example 1:
#  Input: nums = [1,2,3]
#  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
#  Example 2:
#  Input: nums = [0,1]
#  Output: [[0,1],[1,0]]
#  Example 3:
#  Input: nums = [1]
#  Output: [[1]]
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 6
#  -10 <= nums[i] <= 10
#  All the integers of nums are unique.
#  
#  

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        self.dfs(nums, 0, res)

        return res


    def dfs(self, nums: List[int], level: int, answer: List[List[int]]):
        if level == len(nums) - 1:
            answer.append(nums.copy())
            return

        for i in range(level, len(nums)):
            nums[i], nums[level] = nums[level], nums[i]
            self.dfs(nums, level + 1, answer)
            nums[i], nums[level] = nums[level], nums[i]

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        visited = set()
        tmp = []
        self.dfs(nums, visited, tmp, res)

        return res


    def dfs(self, nums: List[int], visited: set, tmp: list[int], answer: List[List[int]]):
        if len(tmp) == len(nums):
            answer.append(tmp.copy())
            return

        for i in range(len(nums)):
            if i not in visited:
                visited.add(i)
                tmp.append(nums[i])
                self.dfs(nums, visited, tmp, answer)
                tmp.pop()
                visited.remove(i)


