class Vector2D(object):

    def __init__(self, vec2d):
        """
        Initialize your data structure here.
        :type vec2d: List[List[int]]
        """
        self.i = 0
        self.j = 0
        self.vector = vec2d
        

    def next(self):
        """
        :rtype: int
        """
        vec2d = self.vector
        res = vec2d[self.i][self.j]
        self.j += 1
        return res
        
    def hasNext(self):
        """
        :rtype: bool
        """
        vec2d = self.vector
        while self.i < len(vec2d) and self.j >= len(vec2d[self.i]):
            self.j = 0
            self.i += 1
            
        if self.i < len(vec2d) and self.j < len(vec2d[self.i]):
            return True
            
        return False
        

# Your Vector2D object will be instantiated and called as such:
# i, v = Vector2D(vec2d), []
# while i.hasNext(): v.append(i.next())