# refer question 300
# O(N * LogN)
class Solution(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        envelopes.sort(key=lambda v: [v[0], -v[1]])
        m = len(envelopes)
        table = []
        
        for i in range(m):
            index = self.lower_bound(table, envelopes[i][1])
            if index == -1:
                table.append(envelopes[i][1])
            else:
                table[index] = envelopes[i][1]

        return len(table)

    def lower_bound(self, table, target):
        # first index no less than target
        if len(table) == 0:
            return -1

        start = 0
        end = len(table) - 1

        while (start + 1 < end):
            mid = start + (end - start) / 2
            if (table[mid] >= target):
                end = mid
            else:
                start = mid

        if table[start] >= target:
            return start

        if table[end] >= target:
            return end

        return -1


# O(N ^ 2) Time Limit Exceeded
# f(i) = max(1, f(j) + 1 if j < i and envelopes[j] < envelopes[i]) 
class Solution2(object):
    def maxEnvelopes(self, envelopes):
        """
        :type envelopes: List[List[int]]
        :rtype: int
        """
        if envelopes is None or len(envelopes) == 0:
            return 0

        envelopes.sort(key=lambda v: v[0])
        m = len(envelopes)
        table = [0 for _ in range(m)]
        table[0] = 1

        for i in range(1, m):
            val = 1
            for j in range(i):
                if envelopes[i][0] != envelopes[j][0] and envelopes[j][1] < envelopes[i][1]:
                    val = max(val, table[j] + 1)

            table[i] = val

        return max(table)