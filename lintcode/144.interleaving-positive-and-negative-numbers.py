class Solution:
    """
    @param: A: An integer array.
    @return: nothing
    """
    def rerange(self, A):
        # write your code here
        
        k = 0
        for i in range(len(A)):
            if A[i] < 0:
                A[i], A[k] = A[k], A[i]
                k += 1
                
        neg_count = k
        pos_count = len(A) - k
        
        isPos = pos_count > neg_count
        
        for i in range(len(A)):
            if (isPos and A[i] < 0) or (not isPos and A[i] > 0):
                A[i], A[k] = A[k], A[i]
                k += 1
            
            isPos = not isPos