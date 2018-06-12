class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        if envelopes is None or len(envelopes) == 0:
            return 0

        envelopes.sort(key=lambda x: x[0])
        table = [i for i in range(len(envelopes))]
        table[0] = 1

        for i in range(len(envelopes)):
            
            pre = i - 1
            while pre >= 0 and (envelopes[i][0] <= envelopes[pre][0] or envelopes[i][1] <= envelopes[pre][1]):
                pre -= 1

            most = 0
            height_i = envelopes[i][1]
            for j in range(pre + 1):
                height_j = envelopes[j][1]
                if height_j < height_i:
                    most = max(most, table[j])

            table[i] = most + 1

        return max(table)