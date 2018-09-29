# f(x) = min(f(x - 1) + diff_color_cost ...)
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
            for j in range(n):
                val = float('inf')
                for p in range(n):
                    if i == 1 or j != p:
                        val = min(val, table[i - 1][p] + costs[i - 1][j])

                table[i][j] = val

        return min(table[-1])