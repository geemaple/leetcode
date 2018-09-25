INF = 2 ** 31 - 1

class Solution(object):

    def check(self, rooms, x, y):
        return (0 <= x < len(rooms) and 0 <= y < len(rooms[x]))

    def wallsAndGates(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: void Do not return anything, modify rooms in-place instead.
        """
        
        queue = []
        visited = set()

        for i in range(len(rooms)):
            for j in range(len(rooms[i])):
                if rooms[i][j] == 0:
                    visited.add((i, j))
                    queue.append((i, j))

        level = 0
        directions = [[0, 1], [-1, 0], [0, -1], [1, 0]]

        while(len(queue) > 0):
        
            size = len(queue)

            for i in range(size):
                x, y = queue.pop(0)
                rooms[x][y] = level

                for j in range(len(directions)):
                    new_x = x + directions[j][0]
                    new_y = y + directions[j][1]

                    if self.check(rooms, new_x, new_y) and (new_x, new_y) not in visited and rooms[new_x][new_y] == INF:
                        visited.add((new_x, new_y))
                        queue.append((new_x, new_y))

            level += 1