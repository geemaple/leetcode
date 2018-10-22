"""
Definition for a point.
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b
"""

class Solution:
    """
    @param grid: a chessboard included 0 (false) and 1 (true)
    @param source: a point
    @param destination: a point
    @return: the shortest path 
    """
    def shortestPath(self, grid, source, destination):
        # write your code here

        directions = [[1, 2], [1, -2], [-1, 2], [-1, -2], [2, 1], [2, -1], [-2, 1], [-2, -1]]
        q = [(source.x, source.y)]
        steps = 0
        grid[source.x][source.y] = True

        while len(q) > 0:
            size = len(q)

            for i in range(size):

                x, y = q.pop(0)

                if x == destination.x and y == destination.y:
                    return steps

                for i in range(8):
                    new_x = x + directions[i][0]
                    new_y = y + directions[i][1]
                    if self.in_bound(grid, new_x, new_y) and not grid[new_x][new_y]:
                        grid[new_x][new_y] = True
                        q.append((new_x, new_y))

            steps += 1

        return -1

    def in_bound(self, grid, x, y):
        return 0 <= x < len(grid) and 0 <= y < len(grid[x])