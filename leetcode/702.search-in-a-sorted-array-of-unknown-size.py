INT_MAX = 2147483647
class Solution(object):
    def search(self, reader, target):
        """
        :type reader: ArrayReader
        :type target: int
        :rtype: int
        """
        
        start = 0
        end = 1
        res = reader.get(end)
        
        while(res != INT_MAX and res < target):
            start = end
            end = end * 2
            res = reader.get(end)
            
        while (start + 1 < end):
            mid = start + (end - start) // 2
            res = reader.get(mid)
            
            if res < target:
                start = mid
            elif res > target:
                end = mid
            else:
                return mid
            
        if reader.get(start) == target:
            return start
            
        if reader.get(end) == target:
            return end
        
        return -1