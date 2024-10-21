#  Tag: Iterator
#  Time: O(*1)
#  Space: O(N)
#  Ref: Leetcode-251
#  Note: -

#  Design an iterator to realize the function of flattening two-dimensional vector.
#  
#  Example 1:
#  ```
#  Input:[[1,2],[3],[4,5,6]]
#  Output:[1,2,3,4,5,6]
#  ```
#  Example 2:
#  ```
#  Input:[[7,9],[5]]
#  Output:[7,9,5]
#  ```
#  
#  

class Vector2D(object):

    # @param vec2d {List[List[int]]}
    def __init__(self, vec2d):
        # Initialize your data structure here
        self.stack = vec2d[::-1]
        self.res = []

    # @return {int} a next element
    def next(self):
        # Write your code here
        return self.res.pop()

    # @return {boolean} true if it has next element
    # or false
    def hasNext(self):
        # Write your code here
        while len(self.stack) > 0 and len(self.res) == 0:
            cur = self.stack.pop()
            self.res.extend(reversed(cur))
        return len(self.res) > 0

# Your Vector2D object will be instantiated and called as such:
# i, v = Vector2D(vec2d), []
# while i.hasNext(): v.append(i.next())