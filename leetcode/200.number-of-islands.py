'''
------------------------->
|
|          top
|           |    
|    left <- -> right
|           |
|         bottom
|
V
'''
class Solution(object):

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        
        # corner case
        if grid is None or len(grid) == 0:
            return 0

        result = 0
        row  = len(grid)
        column = len(grid[0])
        visted = set()

        # find all node = '1'
        for i in range(row):
            for j in range(column):
                if grid[i][j] == '1':
                    # breadth first search and mark it with '0'
                    self.bfs(grid, (i, j), visted)
                    result += 1

        return result


    def check(self, graph, point, visted):
        x , y = point
        row = len(graph)
        column = len(graph[0])

        if point not in visted and 0 <= x < row and 0 <= y < column and graph[x][y] == '1':
            visted.add(point)
            return True
        else:
            return False

    def bfs(self, graph, point, visted):
        # direction = <top, left, bottom, right>
        directionX = [-1, 0, 1, 0]
        directionY = [0, -1, 0, 1]

        queue = [point]
        visted.add(point)

        while(len(queue) > 0):
            x, y = queue.pop(0)
            graph[x][y] = '0'

            for i in range(4):
                neighbor = ((x + directionX[i]), (y + directionY[i]))

                if self.check(graph, neighbor, visted):
                    queue.append(neighbor)