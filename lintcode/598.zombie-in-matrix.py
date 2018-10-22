class Solution:
    """
    @param grid: a 2D integer grid
    @return: an integer
    """
    def zombie(self, grid):
        # write your code here
        people = 0
        visited = set()
        q = []
        
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] == 0:
                    people += 1
        
                if grid[i][j] == 1:
                    q.append((i, j))
                    visited.add((i, j))
                    
        
        directions = [[0, -1], [-1, 0], [0, 1], [1, 0]]

        days = 0
        while people > 0 and len(q) > 0:
            size = len(q)
            
            for _ in range(size):
                tmp = q.pop(0)
                
                for j in range(4):
                    new_x = tmp[0] + directions[j][0]
                    new_y = tmp[1] + directions[j][1]
                    
                    if self.in_bounds(grid, new_x, new_y) and grid[new_x][new_y] == 0 and (new_x, new_y) not in visited:
                        visited.add((new_x, new_y))
                        q.append((new_x, new_y))
                        grid[new_x][new_y] = 1
                        people -= 1
        
            days += 1
        return days if people == 0 else -1
        
    def in_bounds(self, grid, x, y):
        return 0 <= x < len(grid) and 0 <= y < len(grid[x])