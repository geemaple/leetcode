k_max_int = 2147483647
class Solution:
    """
    @param: reader: An instance of ArrayReader.
    @param: target: An integer
    @return: An integer which is the first index of target.
    """
    def searchBigSortedArray(self, reader, target):
        # write your code here
        start = 0
        end = 1
        
        res = reader.get(end)
        while(res != k_max_int and res < target):
            start = end
            end = end << 1
            
            res = reader.get(end)
            
            
        while(start + 1 < end):
            mid = start + (end - start) // 2
            
            res = reader.get(mid)
            if res >= target:
                end = mid
            else:
                start = mid
                
        if reader.get(start) == target:
            return start
            
        if reader.get(end) == target:
            return end
            
        return -1
            