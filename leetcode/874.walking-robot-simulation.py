#  Tag: Array, Hash Table, Simulation
#  Time: O(N)
#  Space: O(K)
#  Ref: -
#  Note: -

#  A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot can receive a sequence of these three possible types of commands:
#  
#  -2: Turn left 90 degrees.
#  -1: Turn right 90 degrees.
#  1 <= k <= 9: Move forward k units, one unit at a time.
#  
#  Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will instead stay in its current location and move on to the next command.
#  Return the maximum Euclidean distance that the robot ever gets from the origin squared (i.e. if the distance is 5, return 25).
#  Note:
#  
#  North means +Y direction.
#  East means +X direction.
#  South means -Y direction.
#  West means -X direction.
#  There can be obstacle in [0,0].
#  
#   
#  Example 1:
#  
#  Input: commands = [4,-1,3], obstacles = []
#  Output: 25
#  Explanation: The robot starts at (0, 0):
#  1. Move north 4 units to (0, 4).
#  2. Turn right.
#  3. Move east 3 units to (3, 4).
#  The furthest point the robot ever gets from the origin is (3, 4), which squared is 32 + 42 = 25 units away.
#  
#  Example 2:
#  
#  Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
#  Output: 65
#  Explanation: The robot starts at (0, 0):
#  1. Move north 4 units to (0, 4).
#  2. Turn right.
#  3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1, 4).
#  4. Turn left.
#  5. Move north 4 units to (1, 8).
#  The furthest point the robot ever gets from the origin is (1, 8), which squared is 12 + 82 = 65 units away.
#  
#  Example 3:
#  
#  Input: commands = [6,-1,-1,6], obstacles = []
#  Output: 36
#  Explanation: The robot starts at (0, 0):
#  1. Move north 6 units to (0, 6).
#  2. Turn right.
#  3. Turn right.
#  4. Move south 6 units to (0, 0).
#  The furthest point the robot ever gets from the origin is (0, 6), which squared is 62 = 36 units away.
#  
#   
#  Constraints:
#  
#  1 <= commands.length <= 104
#  commands[i] is either -2, -1, or an integer in the range [1, 9].
#  0 <= obstacles.length <= 104
#  -3 * 104 <= xi, yi <= 3 * 104
#  The answer is guaranteed to be less than 231.
#  
#  

class Solution:
    def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
        
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        obs = set(map(tuple, obstacles))
        d = 0
        pos = [0, 0]
        res = 0

        for c in commands:
            if c == -2:
                d = (d + 3) % 4
            elif c == -1:
                d = (d + 1) % 4
            else:
                for i in range(c):
                    tmp_x = pos[0] + directions[d][0]
                    tmp_y = pos[1] + directions[d][1]
                    if (tmp_x, tmp_y) in obs:
                        break
                    
                    pos = [tmp_x, tmp_y]
                    
                res = max(res, pos[0] ** 2 + pos[1] ** 2)
                
        return res