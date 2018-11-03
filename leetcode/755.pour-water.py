class Solution(object):
    def pourWater(self, heights, V, K):
        """
        :type heights: List[int]
        :type V: int
        :type K: int
        :rtype: List[int]
        """
        
        for i in range(V):
            
            t = K
            
            #left peak [0: k]
            for left in range(K - 1, -1, -1):
                if heights[left] < heights[t]:
                    t = left
                
                if heights[left] > heights[t]:
                    break
            
            if t == K:
                # right peak [k + 1: ]
                for right in range(K + 1, len(heights)):
                    if heights[right] < heights[t]:
                        t = right
                        
                    if heights[right] > heights[t]:
                        break
                    
            heights[t] += 1
            
        return heights