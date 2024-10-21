#  Tag: Simulation
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  Given a list, each element in the list can be a list or an integer.Flatten it into a simply list with integers.
#  
#  **Example 1:**  
#   
#  Input:  
#  ``` 
#  list = [[1,1],2,[1,1]]
#  ``` 
#  Output:  
#  ``` 
#  [1,1,2,1,1]
#  ``` 
#  Explanation:  
#  
#  Flatten it into a simply list with integers.
#  
#  **Example 2:**  
#   
#  Input:  
#  ``` 
#  list = [1,2,[1,2]]
#  ``` 
#  Output:  
#  ``` 
#  [1,2,1,2]
#  ``` 
#  Explanation:  
#  
#  Flatten it into a simply list with integers.
#  
#  **Example 3:**  
#   
#  Input:  
#  ``` 
#  list = [4,[3,[2,[1]]]]
#  ``` 
#  Output:  
#  ``` 
#  [4,3,2,1]
#  ``` 
#  Explanation:  
#  
#  Flatten it into a simply list with integers.
#  
#  If the element in the given list is a list, it can contain list too.

from collections import deque
class Solution(object):

    # @param nestedList a list, each element in the list 
    # can be a list or integer, for example [1,2,[1,2]]
    # @return {int[]} a list of integer
    def flatten(self, nestedList):
        # Write your code here
        res = []
        for x in nestedList:
            if isinstance(x, list):
                res += self.flatten(x)
            else:
                res.append(x)

        return res
    
class Solution(object):
    # @param nestedList a list, each element in the list 
    # can be a list or integer, for example [1,2,[1,2]]
    # @return {int[]} a list of integer
    def flatten(self, nestedList):
        # Write your code here
        res = []
        stack = nestedList[::-1]

        while len(stack) > 0:
            cur = stack.pop()
            if isinstance(cur, int):
                res.append(cur)
            else:
                stack.extend(reversed(cur))

        return res