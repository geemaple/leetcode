
# two pointers beats 71%
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if height is None or len(height) < 3:
            return 0

        size = len(height)
        left = 0
        right =  size - 1
        left_max = height[left]
        right_max = height[right]

        result = 0
        while left <= right:
            if left_max < right_max:
                result += max(0, left_max - height[left])
                left_max = max(left_max, height[left])
                left += 1
            else:
                result += max(0, right_max - height[right])
                right_max = max(right_max, height[right])
                right -=1

        return result


#scan twice beats 100%
class Solution2(object):
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