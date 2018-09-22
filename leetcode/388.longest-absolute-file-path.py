class Solution(object):
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        lines = input.split('\n')
        table = {}
        longest = 0

        for i in range(len(lines)):
            l = lines[i]
            level = l.count('\t')
            size = len(l[level:])

            if '.' in l:
                longest = max(longest, table.get(level - 1, 0) + size)
            else:
                table[level] = table.get(level - 1, 0) + size + 1

        return longest