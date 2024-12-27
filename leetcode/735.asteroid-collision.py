#  Tag: Array, Stack, Simulation
#  Time: O(N)
#  Space: O(N)
#  Ref: -
#  Note: -

#  We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
#  For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
#  Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
#   
#  Example 1:
#  
#  Input: asteroids = [5,10,-5]
#  Output: [5,10]
#  Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
#  
#  Example 2:
#  
#  Input: asteroids = [8,-8]
#  Output: []
#  Explanation: The 8 and -8 collide exploding each other.
#  
#  Example 3:
#  
#  Input: asteroids = [10,2,-5]
#  Output: [10]
#  Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
#  
#   
#  Constraints:
#  
#  2 <= asteroids.length <= 104
#  -1000 <= asteroids[i] <= 1000
#  asteroids[i] != 0
#  
#  
    
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for x in asteroids:
            destroyed = False
            while (len(stack) > 0 and stack[-1] > 0 and x < 0):
                if stack[-1] + x == 0:
                    stack.pop()
                    destroyed = True
                    break

                if stack[-1] + x > 0:
                    destroyed = True
                    break

                if stack[-1] + x < 0:
                    stack.pop()
       
            if not destroyed:
                stack.append(x)
                
        return stack
    
class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stack = []
        for x in asteroids:
            while (len(stack) > 0 and stack[-1] > 0 and x < 0):
                if stack[-1] + x == 0:
                    stack.pop()
                    break

                if stack[-1] + x > 0:
                    break

                if stack[-1] + x < 0:
                    stack.pop()
            else:
                stack.append(x)
                
        return stack