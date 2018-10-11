class Solution:
    """
        @param L: Given n pieces of wood with length L[i]
        @param k: An integer
        @return: The maximum length of the small pieces
        """
    def woodCut(self, L, k):
        # write your code here
        
        if L is None or len(L) == 0:
            return 0
        
        start = 0
        end = max(L)
        
        while(start + 1 < end):
            mid = start + (end - start) / 2
            
            if self.is_sufficent(L, mid, k):
                start = mid
            else:
                end = mid
        
    return end if self.is_sufficent(L, end, k) else start

    def is_sufficent(self, L, length, nums):
        
        if length == 0:
            return False
        
        ans = 0
        for i in range(len(L)):
            ans += L[i] // length
    
        return ans >= nums
