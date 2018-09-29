# optimize version of Solution2
# find two smallest k1, k2 where k1 < k2 in table[pre]
# table[pre][k1] + diff_color_cost = k2 + diff_color_cost
# table[pre][other] + diff_color_cost = k1 + diff_color_cost
# O(M * N)
class Solution(object):
    def minCostII(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        
        if costs is None or len(costs) == 0:
            return 0

        m = len(costs)
        n = len(costs[0])

        table = [[0 for _ in range(n)] for _ in range(m + 1)]

        for i in range(1, m + 1):
            min1 = float('inf')
            min2 = float('inf')

            for j in range(n):
                if table[i - 1][j] < min1:
                    min2 = min1
                    min1 = table[i - 1][j]
                elif table[i - 1][j] < min2:
                    min2 = table[i - 1][j]

            for j in range(n):
                val = min2 if n > 1 and table[i - 1][j] == min1 else min1
                table[i][j] = val + costs[i - 1][j]

        return min(table[-1])

# f(x) = min(f(x - 1) + diff_color_cost ...)
class Solution2(object):
    def minCostII(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        
        if costs is None or len(costs) == 0:
            return 0

        m = len(costs)
        n = len(costs[0])

        table = [[0 for _ in range(n)] for _ in range(m + 1)]

        for i in range(1, m + 1):
            for j in range(n):
                val = float('inf')
                for p in range(n):
                    if i == 1 or j != p:
                        val = min(val, table[i - 1][p] + costs[i - 1][j])

                table[i][j] = val

        return min(table[-1])