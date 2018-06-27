# O(N^2) Time Limit Exceeded
class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        if envelopes is None or len(envelopes) == 0:
            return 0

        envelopes.sort(key=lambda x: x[0])
        table = []
        table.append(1)

        for i in range(1, len(envelopes)):
            
            count = 1
            for j in range(len(table)):
                if (envelopes[i][0] > envelopes[j][0] and envelopes[i][1] > envelopes[j][1] and count < table[j] + 1):
                    count = table[j] + 1

            table.append(count)

        return max(table)
