class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        nums_set = set(nums)
        ans = 0
        for i in range(len(nums)):

            if nums[i] in nums_set:
                nums_set.remove(nums[i])
                upper = lower = nums[i]

                while (lower - 1 in nums_set):
                    nums_set.remove(lower - 1)
                    lower -= 1

                while (upper + 1 in nums_set):
                    nums_set.remove(upper + 1)
                    upper += 1


                ans = max(ans, upper - lower + 1)

        return ans

class UnionFind(object):
    def __init__(self, count):

        self.table = [0] * count
        self.count = {}

        for i in range(count):
            self.table[i] = i
            self.count[i] = 1

    def find(self, a):
        if self.table[a] == a:
            return a

        self.table[a] = self.find(self.table[a])
        return self.table[a]

    def connect(self, a, b):
        root_a = self.find(a)
        root_b = self.find(b)

        if root_a != root_b:
            self.table[root_a] = root_b
            self.count[root_b] += self.count[root_a]

    def max_group(self):
        res = 0
        for k, v in self.count.iteritems():
            res = max(res, v)

        return res


class Solution2(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mapping = {}
        uf = UnionFind(len(nums))
        for i in range(len(nums)):
            mapping[nums[i]] = i

        for i in range(len(nums)):
            num = nums[i]

            if mapping[num] != i:
                continue

            if num + 1 in mapping:
                uf.connect(i, mapping[num + 1])

        return uf.max_group()