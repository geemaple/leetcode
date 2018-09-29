class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        table = []

        for i in range(num + 1):
            table.append(i % 2)
            pre = i >> 1

            if pre > 0:
                table[i] += table[pre]

        return table        
