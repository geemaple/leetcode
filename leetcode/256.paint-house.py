# f[cost][color1] = min(f[cost - 1][color2] + costs[color1], f[cost - 1][color3] + costs[color1])
class Solution(object):
    def minCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        if costs is None or len(costs) == 0:
            return 0

        size = len(costs)
        color_size = len(costs[0])

        table = [[0 for _ in range(color_size)] for i in range(size + 1)]

        for i in range(1, size + 1):
            for j in range(color_size):
                cost = float('inf')
                for p in range(color_size):
                    if j != p:
                        cost = min(cost, table[i - 1][p] + costs[i - 1][j])
                table[i][j] = cost

        return min(table[-1])