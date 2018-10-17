# O(N^2) with sorted list
class Solution(object):
    def kEmptySlots(self, flowers, k):
        blooming = []
        for day, flower in enumerate(flowers, 1):
            i = bisect.bisect(blooming, flower)
            for neighbor in blooming[i-(i>0):i+1]:
                if abs(flower - neighbor) - 1 == k:
                    return day
            blooming.insert(i, flower)
        return -1