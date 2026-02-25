#  Tag: Array, Hash Table, Divide and Conquer, Segment Tree, Prefix Sum
#  Time: -
#  Space: -
#  Ref: -
#  Note: -

#  You are given an integer array nums.
#  A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
#  Return the length of the longest balanced subarray.
#   
#  Example 1:
#  
#  Input: nums = [2,5,4,3]
#  Output: 4
#  Explanation:
#  
#  The longest balanced subarray is [2, 5, 4, 3].
#  It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
#  
#  
#  Example 2:
#  
#  Input: nums = [3,2,2,5,4]
#  Output: 5
#  Explanation:
#  
#  The longest balanced subarray is [3, 2, 2, 5, 4].
#  It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [3, 5]. Thus, the answer is 5.
#  
#  
#  Example 3:
#  
#  Input: nums = [1,2,3,2]
#  Output: 3
#  Explanation:
#  
#  The longest balanced subarray is [2, 3, 2].
#  It has 1 distinct even number [2] and 1 distinct odd number [3]. Thus, the answer is 3.
#  
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 105
#  1 <= nums[i] <= 105
#  
#  

class SegmentTree:
    """Segment Tree over array of size n"""

    def __init__(self, n: int):
        self.n = n
        self.size = 4 * n
        self.sum = [0] * self.size
        self.min = [0] * self.size
        self.max = [0] * self.size

    def _pull(self, node: int):
        """Helper to recompute information of node by it's children"""

        l, r = node * 2, node * 2 + 1

        self.sum[node] = self.sum[l] + self.sum[r]
        self.min[node] = min(self.min[l], self.sum[l] + self.min[r])
        self.max[node] = max(self.max[l], self.sum[l] + self.max[r])

    def update(self, idx: int, val: int):
        """Update value by index idx in original array"""

        def _update(node: int = 1, l: int = 0, r: int = self.n - 1):
            if l == r:
                self.sum[node] = val
                self.min[node] = val
                self.max[node] = val
                return

            m = l + (r - l) // 2
            if idx <= m:
                _update(node * 2, l, m)
            else:
                _update(node * 2 + 1, m + 1, r)

            self._pull(node)

        return _update()

    def find_rightmost_prefix(self, target: int = 0) -> int:
        """Find rightmost index r with prefixsum(r) = target"""

        def _exist(node: int, sum_before: int):
            return self.min[node] <= target - sum_before <= self.max[node]

        def _find(node: int = 1, l: int = 0, r: int = self.n - 1, sum_before: int = 0):
            if not _exist(node, sum_before):
                return -1
            if l == r:
                return l

            m = l + (r - l) // 2
            lchild, rchild = node * 2, node * 2 + 1

            # Check right half first
            sum_before_right = self.sum[lchild] + sum_before
            if _exist(rchild, sum_before_right):
                return _find(rchild, m + 1, r, sum_before_right)

            return _find(lchild, l, m, sum_before)

        return _find()


class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)

        stree = SegmentTree(n)  # SegmentTree over balance array for current l
        first = dict()  # val -> first occurence idx for current l

        result = 0
        for l in reversed(range(n)):
            num = nums[l]
    
            # If x already had a first occurrence to the right, remove that old marker.
            if num in first:
                stree.update(first[num], 0)

            # Now x becomes first occurrence at l.
            first[num] = l
            stree.update(l, 1 if num % 2 == 0 else -1)

            # Find rightmost r >= l such that sum(w[l..r]) == 0
            r = stree.find_rightmost_prefix(target=0)
            if r >= l:
                result = max(result, r - l + 1)

        return result