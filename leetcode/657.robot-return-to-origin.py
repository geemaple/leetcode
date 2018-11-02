class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        vertical = 0
        horizontal = 0
        mapping = {"U": 1, "D": -1, "R": 1, "L": -1}
        
        for direction in moves:
            if direction == "U" or direction == "D":
                vertical += mapping[direction]
            else:
                horizontal += mapping[direction]
        
        
        return horizontal == 0 and vertical == 0