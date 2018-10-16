"""
Definition of Interval.
class Interval(object):
    def __init__(self, start, end):
        self.start = start
        self.end = end
"""

class Solution:
    """
    @param airplanes: An interval array
    @return: Count of airplanes are in the sky.
    """
    def countOfAirplanes(self, airplanes):
        dots = []
        for plane in airplanes:
            dots.append([plane.start, 1])
            dots.append([plane.end, -1])
            
        count, result = 0, 0
        for _, delta in sorted(dots):
            count += delta
            result = max(result, count)
            
        return result