# f(k)(i) = min(max(f(k - 1)(j), rest) where 0 <= j <= i)
# O(k * N^2) Time Limit Exceeded
class Solution:
    """
    @param pages: an array of integers
    @param k: An integer
    @return: an integer
    """
    def copyBooks(self, pages, k):
        # write your code here
        if pages is None or len(pages) == 0:
            return 0

        m = len(pages)

        if k > m:
            k = m

        table = [[float('inf') for _ in range(m + 1)] for _ in range(k + 1)]

        table[0][0] = 0

        for t in range(1, k + 1):

            table[t][0] = 0

            for i in range(1, m + 1):
                value = float('inf') 
                rest = 0
                for j in range(i, -1, -1):
                    time = max(table[t - 1][j], rest)
                    value = min(value, time)
                    if j - 1 >= 0:
                        rest += pages[j - 1]

                table[t][i] = value

        return table[-1][-1]

# binary-search
# NLogA A = possible answer
class Solution2:
    """
    @param pages: an array of integers
    @param k: An integer
    @return: an integer
    """
    def copyBooks(self, pages, k):
        # write your code here
        
        start = 0
        end = 0
        
        for work in pages:
            start = max(start, work)
            end += work
            
        while (start + 1 < end):
            mid = start + (end - start) // 2
            
            if self.canFinish(pages, mid, k):
                end = mid
            else:
                start = mid
                
        return start if self.canFinish(pages, start, k) else end
        
        
    def canFinish(self, pages, minutes, people):
        headcount = 0
        unit = minutes
        i = 0
        
        while i < len(pages):
            
            while(i + 1 < len(pages) and unit - pages[i] >= pages[i + 1]):
                unit -= pages[i]
                i += 1
                
            headcount += 1    
            unit = minutes
            i += 1
        
        return headcount <= people