import heapq

class Solution(object):

    def __init__(self):
        self.borders = []
        self.visited = set()
        self.directions = [[0, 1], [-1, 0], [0, -1], [1, 0]]

    def trapRainWater(self, heightMap):
        """
        :type heightMap: List[List[int]]
        :rtype: int
        """
        if heightMap is None or len(heightMap) < 3 or len(heightMap[0]) < 3:
            return 0

        row = len(heightMap)
        col = len(heightMap[0])

        self.initialize(heightMap, row, col)

        result = 0
        while len(self.borders) > 0:
            border_height, x, y = heapq.heappop(self.borders)
            for d in self.directions:
                new_x = x + d[0]
                new_y = y + d[1]
                if (self.in_boundary(new_x, new_y, heightMap) and (new_x, new_y) not in self.visited):
                    new_height = heightMap[new_x][new_y]
                    result += max(0, border_height - new_height)
                    self.add(max(new_height, border_height), new_x, new_y, col)

        return result
        
    def initialize(self, heightMap, row, col):
        for i in range(row):
            self.add(heightMap[i][0], i, 0, col)
            self.add(heightMap[i][col - 1], i, col - 1, col)

        for j in range(1, col - 1):
            self.add(heightMap[0][j], 0, j, col)
            self.add(heightMap[row - 1][j], row - 1, j, col)

    def add(self, height, x, y, col):
        self.visited.add((x, y))
        heapq.heappush(self.borders, (height, x, y))

    def in_boundary(self, x, y, heightMap):
        return (0 <= x < len(heightMap) and 0 <= y < len(heightMap[x]))