class Solution(object):
    def minArea(self, image, x, y):
        """
        :type image: List[List[str]]
        :type x: int
        :type y: int
        :rtype: int
        """
        top = self.searchTop(image, x, y)
        bottom = self.searchBottom(image, x, y)
        left = self.searchLeft(image, x, y, top, bottom)
        right = self.searchRight(image, x, y, top, bottom)
        
        return (bottom - top + 1) * (right - left + 1)
        
    def checkRow(self, image, row, leftBoundry, rightBoundry):
        for j in range(leftBoundry, rightBoundry + 1):
            if image[row][j] == '1':
                return True
        return False
        
    def searchTop(self, image, x, y):
        start = 0
        end = x
        
        while(start + 1 < end):
            mid = start + (end - start) // 2
            if self.checkRow(image, mid, 0, len(image[0]) - 1):
                end = mid
            else:
                start = mid
                
        return start if self.checkRow(image, start, 0, len(image[0]) - 1) else end
    

    def searchBottom(self, image, x, y):
        start = x
        end = len(image) - 1
        
        while(start + 1 < end):
            mid = start + (end - start) // 2
            if self.checkRow(image, mid, 0, len(image[0]) - 1):
                start = mid
            else:
                end = mid
                
        return end if self.checkRow(image, end, 0, len(image[0]) - 1) else start
    
    def checkCol(self, image, col, topBoundry, bottomBoundry):
        for i in range(topBoundry, bottomBoundry + 1):
            if image[i][col] == '1':
                return True
        return False    
    
    def searchLeft(self, image, x, y, topBoundry, bottomBoundry):
        start = 0
        end = y
        
        while(start + 1 < end):
            mid = start + (end - start) // 2
            if self.checkCol(image, mid, topBoundry, bottomBoundry):
                end = mid
            else:
                start = mid
                
        return start if self.checkCol(image, start, topBoundry, bottomBoundry) else end
            
        
    def searchRight(self, image, x, y, topBoundry, bottomBoundry):
        start = y
        end = len(image[0]) - 1
        
        while(start + 1 < end):
            mid = start + (end - start) // 2
            if self.checkCol(image, mid, topBoundry, bottomBoundry):
                start = mid
            else:
                end = mid
                
        return end if self.checkCol(image, end, topBoundry, bottomBoundry) else start