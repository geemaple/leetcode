#scan twice
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        
        if height is None or len(height) < 3:
            return 0

        size = len(height)
        left_maxes = [0] * size
        right_maxes = [0] * size

        # scan left to right
        cur_max = -1
        for i in range(size):
            cur_max = max(cur_max, height[i])
            left_maxes[i] = cur_max

        # scan right to left
        cur_max = -1
        for i in range(size - 1, -1, -1):
            cur_max = max(cur_max, height[i])
            right_maxes[i] = cur_max

        result = 0
        for i in range(1, size - 1):
            bound = min(left_maxes[i], right_maxes[i])
            if bound - height[i] > 0:
                result += (bound - height[i])

        return result