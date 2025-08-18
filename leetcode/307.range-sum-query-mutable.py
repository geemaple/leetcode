#  Tag: Array, Design, Binary Indexed Tree, Segment Tree
#  Time: O(logN)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given an integer array nums, handle multiple queries of the following types:
#  
#  Update the value of an element in nums.
#  Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
#  
#  Implement the NumArray class:
#  
#  NumArray(int[] nums) Initializes the object with the integer array nums.
#  void update(int index, int val) Updates the value of nums[index] to be val.
#  int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
#  
#   
#  Example 1:
#  
#  Input
#  ["NumArray", "sumRange", "update", "sumRange"]
#  [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
#  Output
#  [null, 9, null, 8]
#  
#  Explanation
#  NumArray numArray = new NumArray([1, 3, 5]);
#  numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
#  numArray.update(1, 2);   // nums = [1, 2, 5]
#  numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
#  
#   
#  Constraints:
#  
#  1 <= nums.length <= 3 * 104
#  -100 <= nums[i] <= 100
#  0 <= index < nums.length
#  -100 <= val <= 100
#  0 <= left <= right < nums.length
#  At most 3 * 104 calls will be made to update and sumRange.
#  
#  
class segmentTree:
    def __init__(self, a: list):
        n = len(a)
        self.seg = [0 for i in range(4 * n)]
        self.build(a, 1, 0, n - 1)
        print(self.seg)

    def build(self, a: list, v: int, i: int, j: int):
        if i == j:
            self.seg[v] = a[i]
            return

        m = (i + j) // 2
        self.build(a, 2 * v, i, m)
        self.build(a, 2 * v + 1, m + 1, j)
        self.seg[v] = self.seg[2 * v] + self.seg[2 * v + 1]

    def query(self, v: int, i: int, j: int, l: int, r: int) -> int:
        if l > r:
            return 0

        if l == i and r == j:
            return self.seg[v]

        m = (i + j) // 2
        left = self.query(2 * v, i, m, l, min(m, r))
        right = self.query(2 * v + 1, m + 1, j, max(m + 1, l), r)
        return left + right

    def update(self, v: int, i: int, j: int, pos: int, val: int):
        if i == j:
            self.seg[v] = val
            return

        m = (i + j) // 2
        if pos <= m:
            self.update(2 * v, i, m, pos, val)
        else:
            self.update(2 * v + 1, m + 1, j, pos, val)

        self.seg[v] = self.seg[2 * v] + self.seg[2 * v + 1]

class NumArray:

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.seg = segmentTree(nums)

    def update(self, index: int, val: int) -> None:
        self.seg.update(1, 0, self.n - 1, index, val)        

    def sumRange(self, left: int, right: int) -> int:
        return self.seg.query(1, 0, self.n - 1, left, right)

class SegmentTreeNode:
    def __init__(self, start: int, end: int, val: int):
        self.start = start
        self.end = end
        self.val = val
        self.left = None
        self.right = None

class SegmentTree:
    def __init__(self, nums: list):
        self.root = self.build(nums, 0, len(nums) - 1)

    def build(self, nums: list, start: int, end: int):
        node = SegmentTreeNode(start, end, nums[start])
        if start == end:
            return node

        mid = (start + end) // 2
        node.left = self.build(nums, start, mid)
        node.right = self.build(nums, mid + 1, end)
        node.val = node.left.val + node.right.val
        return node

    def update(self, node: SegmentTreeNode, index: int, val: int):
        if index == node.start and index == node.end:
            node.val = val
            return

        mid = (node.start + node.end) // 2
        if index <= mid:
            self.update(node.left, index, val)
        else:
            self.update(node.right, index, val)

        node.val = node.left.val + node.right.val
        
    def query(self, node: SegmentTreeNode, start: int, end: int) -> int:
        if start == node.start and end == node.end:
            return node.val
        
        mid = (node.start + node.end) // 2
        if end <= mid:
            return self.query(node.left, start, end)
        elif start > mid:
            return self.query(node.right, start, end)
        else:
            left_val = self.query(node.left, start, mid)
            right_val = self.query(node.right, mid + 1, end)
            return left_val + right_val

class NumArray:

    def __init__(self, nums: List[int]):
        self.tree = SegmentTree(nums)
 
    def update(self, index: int, val: int) -> None:
        self.tree.update(self.tree.root, index, val)

    def sumRange(self, left: int, right: int) -> int:
        return self.tree.query(self.tree.root, left, right)

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)